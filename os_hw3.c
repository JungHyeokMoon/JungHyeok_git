








//
// Virual Memory Simulator Homework
// One-level page table system with FIFO and LRU
// Two-level page table system with LRU
// Inverted page table with a hashing system 
// Submission Year: 2019
// Student Name: MoonJungHyeok	
// Student Number: B511057
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define PAGESIZEBITS 12			// page size = 4Kbytes
#define VIRTUALADDRBITS 32		// virtual address space size = 4Gbyte
typedef enum { false, true } bool;
typedef struct pageTableEntry {
	int level;				// page table level (1 or 2)
	char valid;
	struct pageTableEntry* secondLevelPageTable;	// valid if this entry is forthe first level page table (level = 1)
	int frameNumber;// valid if this entry is for  the second level page table (level = 2)

}pageTableEntry;

bool s_skip = false; //FASLSE=> 생략안함
int simtype = 0;

typedef struct invertedPageTableEntry {
	int pid;					// process id
	int virtualPageNumber;		// virtual page number
	int frameNumber;			// frame number allocated
	struct invertedPageTableEntry* next;
}invertedPageTableEntry;

typedef struct procEntry {
	char* traceName;			// the memory trace name
	int pid;					// process (trace) id
	int ntraces;				// the number of memory traces
	int num2ndLevelPageTable;	// The 2nd level page created(allocated);
	int numIHTConflictAccess; 	// The number of Inverted Hash Table Conflict Accesses
	int numIHTNULLAccess;		// The number of Empty Inverted Hash Table Accesses
	int numIHTNonNULLAcess;		// The number of Non Empty Inverted Hash Table Accesses
	int numPageFault;			// The number of page faults
	int numPageHit;				// The number of page hits
	pageTableEntry* firstLevelPageTable;
	FILE* tracefp;
	//	unsigned virtualaddress[MAXNTRACE];
}procEntry;

typedef struct framePage {
	int number;			// frame number
	int pid;			// Process id that owns the frame
	int virtualPageNumber;			// virtual page number using the frame
	struct framePage* lruLeft;	// for LRU circular doubly linked list
	struct framePage* lruRight; // for LRU circular doubly linked list
}framePage;

framePage* oldestFrame;
framePage* newestFrame;// the oldest frame pointer
int firstLevelBits, phyMemSizeBits, numProcess;



void initPhyMem(framePage* phyMem, unsigned int nFrame) {
	int i;
	for (i = 0; i < nFrame; i++) {
		phyMem[i].number = i;
		phyMem[i].pid = -1;
		phyMem[i].virtualPageNumber = -1;
		phyMem[i].lruLeft = &phyMem[(i - 1 + nFrame) % nFrame];
		phyMem[i].lruRight = &phyMem[(i + 1 + nFrame) % nFrame];
	}

	oldestFrame = &phyMem[0];
	newestFrame = (oldestFrame->lruLeft);
}




void oneLevelVMSimFIFO(procEntry* procTable, framePage* phyMemFrames) {
	int i;
	unsigned int offset_and_op = 0x00000FFF;
	int j = 0;
	int cnt = 0;
	int nFrame = (1 << (phyMemSizeBits - PAGESIZEBITS));
	bool flag = false;

	while (1) {
		unsigned int addr;
		char rw;
		for (i = 0; i < numProcess; i++) {
			fscanf(procTable[i].tracefp, "%x %c", &addr, &rw);
			if (feof(procTable[i].tracefp) != 0) {
				flag = true;
				break;
			}
			unsigned int vpn = addr >> 12;
			unsigned int offset = addr & offset_and_op;
			if (procTable[i].firstLevelPageTable[vpn].valid == 0) {
				procTable[i].numPageFault++;
				if (cnt >= nFrame) {
					procTable[oldestFrame->pid].firstLevelPageTable[oldestFrame->virtualPageNumber].valid = 0;
					oldestFrame->pid = i;
					oldestFrame->virtualPageNumber = vpn;
					procTable[i].firstLevelPageTable[vpn].valid = 1;
					procTable[i].firstLevelPageTable[vpn].frameNumber = oldestFrame->number;
					oldestFrame = oldestFrame->lruRight;
				}
				else {
					phyMemFrames[j].pid = i;
					phyMemFrames[j].virtualPageNumber = vpn;
					procTable[i].firstLevelPageTable[vpn].frameNumber = j;
					procTable[i].firstLevelPageTable[vpn].valid = 1;
					j++;
				}
				cnt++;
			}
			else {
				if (phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].pid == i) {
					procTable[i].numPageHit++;
				}
				else {
					procTable[i].numPageFault++;
					if (cnt >= nFrame) {
						procTable[oldestFrame->pid].firstLevelPageTable[oldestFrame->virtualPageNumber].valid = 0;
						oldestFrame->pid = i;
						oldestFrame->virtualPageNumber = vpn;
						procTable[i].firstLevelPageTable[vpn].valid = 1;
						procTable[i].firstLevelPageTable[vpn].frameNumber = oldestFrame->number;
						oldestFrame = oldestFrame->lruRight;
					}
					else {
						phyMemFrames[j].pid = i;
						phyMemFrames[j].virtualPageNumber = vpn;
						procTable[i].firstLevelPageTable[vpn].frameNumber = j;
						procTable[i].firstLevelPageTable[vpn].valid = 1;
						j++;
					}
					cnt++;
				}
			}
			procTable[i].ntraces++;
			unsigned int physicaframeindex = ((procTable[i].firstLevelPageTable[vpn].frameNumber) << 12) | offset;
			if (s_skip == false) {
				printf("One-Level procID %d traceNumber %d virtual addr %x physical addr %x\n", i, procTable[i].ntraces, addr, physicaframeindex);
			}
		}
		if (flag)break;
	}


	for (i = 0; i < numProcess; i++) {
		printf("**** %s *****\n", procTable[i].traceName);
		printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
		printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
		printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
		assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
	}
	for (i = 0; i < numProcess; i++) {
		free(procTable[i].firstLevelPageTable);
		procTable[i].firstLevelPageTable = NULL;
	}
}


void oneLevelVMSimLRU(procEntry* procTable, framePage* phyMemFrames) {
	int i;
	unsigned int offset_and_op = 0x00000FFF;
	bool flag = false;
	//int j = 1;
	while (1) {
		unsigned int addr;
		char rw;
		for (i = 0; i < numProcess; i++) {
			fscanf(procTable[i].tracefp, "%x %c", &addr, &rw);
			if (feof(procTable[i].tracefp) != 0) {
				flag = true;
				break;
			}
			unsigned int vpn = addr >> PAGESIZEBITS;
			unsigned int offset = addr & offset_and_op;

			if (procTable[i].firstLevelPageTable[vpn].valid == 1) {
				if (phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].pid == i && phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].virtualPageNumber == vpn) {
					procTable[i].numPageHit++;

					if (&phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber] == newestFrame) {
						//printf("%d th trace : newsest Frame hit			  , newest Frame->number : %d, newstFrame->vpn : %x\n", j,newestFrame->number, newestFrame->virtualPageNumber);
						//continue;
					}
					else if (&phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber] == oldestFrame) {


						newestFrame = newestFrame->lruRight;
						oldestFrame = oldestFrame->lruRight;
					}
					else {
						phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].lruLeft->lruRight = phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].lruRight;
						phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].lruRight->lruLeft = phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].lruLeft;
						newestFrame->lruRight = &phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber];
						phyMemFrames[procTable[i].firstLevelPageTable[vpn].frameNumber].lruLeft = newestFrame;
						newestFrame = newestFrame->lruRight;
						newestFrame->lruRight = oldestFrame;
						oldestFrame->lruLeft = newestFrame;
					}
				}
			}
			else {
				procTable[i].numPageFault++;
				if (oldestFrame->pid == -1) {
					oldestFrame->pid = i;
					oldestFrame->virtualPageNumber = vpn;
					procTable[i].firstLevelPageTable[vpn].valid = 1;
					procTable[i].firstLevelPageTable[vpn].frameNumber = oldestFrame->number;
					newestFrame = newestFrame->lruRight;
					oldestFrame = oldestFrame->lruRight;
				}
				else {
					procTable[oldestFrame->pid].firstLevelPageTable[oldestFrame->virtualPageNumber].valid = 0;
					procTable[oldestFrame->pid].firstLevelPageTable[oldestFrame->virtualPageNumber].frameNumber = -1;
					oldestFrame->virtualPageNumber = vpn;
					oldestFrame->pid = i;
					procTable[i].firstLevelPageTable[vpn].frameNumber = oldestFrame->number;
					procTable[i].firstLevelPageTable[vpn].valid = 1;
					newestFrame = newestFrame->lruRight;
					oldestFrame = oldestFrame->lruRight;
				}
			}
			procTable[i].ntraces++;
			unsigned int physicaframeindex = ((procTable[i].firstLevelPageTable[vpn].frameNumber) << 12) | offset;
			if (s_skip == false) {
				printf("One-Level procID %d traceNumber %d virtual addr %x physical addr %x\n", i, procTable[i].ntraces, addr, physicaframeindex);
			}
		}
		if (flag)break;
	}



	for (i = 0; i < numProcess; i++) {
		printf("**** %s *****\n", procTable[i].traceName);
		printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
		printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
		printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
		assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
	}
	for (i = 0; i < numProcess; i++) {
		free(procTable[i].firstLevelPageTable);
		procTable[i].firstLevelPageTable = NULL;
	}
}

void twoLevelVMSim(procEntry* procTable, framePage* phyMemFrames) {
	int i;
	unsigned int offset_and_op = 0x00000FFF;

	bool flag = false;
	unsigned int secondlevelBits = VIRTUALADDRBITS - (firstLevelBits + PAGESIZEBITS);

	//int j = 1;
	unsigned int forsecond = ((1 << secondlevelBits) - 1) << PAGESIZEBITS;
	unsigned int forfirst = ~((1 << (VIRTUALADDRBITS - firstLevelBits)) - 1);
	while (1) {
		unsigned int addr;
		char rw;
		for (i = 0; i < numProcess; i++) {
			fscanf(procTable[i].tracefp, "%x %c", &addr, &rw);
			if (feof(procTable[i].tracefp) != 0) {
				flag = true;
				break;
			}
			unsigned int offset = addr & offset_and_op;
			unsigned int vpn = addr >> PAGESIZEBITS;
			unsigned int firstlevelpagenumber = (addr & forfirst) >> (VIRTUALADDRBITS - firstLevelBits);
			unsigned int secondlevelpagenumber = (addr & forsecond) >> PAGESIZEBITS;

			if (procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable != NULL) {

				if (procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid == 1) {

					if (phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].pid == i &&
						phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].virtualPageNumber == vpn) {
						procTable[i].numPageHit++;

						if (&phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber] == newestFrame) {
							//printf("%d th trace : newsest Frame hit			  , newest Frame->number : %d, newstFrame->vpn : %x\n", j,newestFrame->number, newestFrame->virtualPageNumber);
							//continue;
						}//가장최근에꺼참조했으면 그냥 가만히있으면된다
						else if (&phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber] == oldestFrame) {
							newestFrame = newestFrame->lruRight;
							oldestFrame = oldestFrame->lruRight;
						}
						else {
							phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].lruLeft->lruRight = phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].lruRight;
							phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].lruRight->lruLeft = phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].lruLeft;
							newestFrame->lruRight = &phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber];
							phyMemFrames[procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber].lruLeft = newestFrame;
							newestFrame = newestFrame->lruRight;
							newestFrame->lruRight = oldestFrame;
							oldestFrame->lruLeft = newestFrame;
						}//중간에꺼뽑아냈으면 포인터들 다시 셋팅
					}
					else { //valid는 켜져있는데 phymemory에 pid가 다른경우
						procTable[i].numPageFault++;
						if (oldestFrame->pid == -1) {
							oldestFrame->pid = i;
							oldestFrame->virtualPageNumber = vpn;
							procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid = 1;
							procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber = oldestFrame->number;
							newestFrame = newestFrame->lruRight;
							oldestFrame = oldestFrame->lruRight;
							//printf("%d th trace : front fill and send rear      : newsetFrame->number : %d, newsetFrame->vpn : %x\n", j,newestFrame->number, newestFrame->virtualPageNumber);
						}//not full
						else {
							procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].valid = 0;
							procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].frameNumber = -1;
							procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].level = 2;
							oldestFrame->virtualPageNumber = vpn;
							oldestFrame->pid = i;
							procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber = oldestFrame->number;
							procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid = 1;
							procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].level = 2;
							newestFrame = newestFrame->lruRight;
							oldestFrame = oldestFrame->lruRight;
							//printf("%d th trace : full -> change -> send rear	  : newstFrame->number : %d, newestFrame->vpn : %x\n",j, newestFrame->number, newestFrame->virtualPageNumber);
						}//full
						//printf("page fault\n");
					}
				}
				else {//valid 가 0인경우
					procTable[i].numPageFault++;
					if (oldestFrame->pid == -1) {
						oldestFrame->pid = i;
						oldestFrame->virtualPageNumber = vpn;
						procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid = 1;
						procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber = oldestFrame->number;
						newestFrame = newestFrame->lruRight;
						oldestFrame = oldestFrame->lruRight;
						//printf("%d th trace : front fill and send rear      : newsetFrame->number : %d, newsetFrame->vpn : %x\n", j,newestFrame->number, newestFrame->virtualPageNumber);
					}//not full
					else {
						procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].valid = 0;
						procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].frameNumber = -1;
						procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].level = 2;
						oldestFrame->virtualPageNumber = vpn;
						oldestFrame->pid = i;
						procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber = oldestFrame->number;
						procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid = 1;
						newestFrame = newestFrame->lruRight;
						oldestFrame = oldestFrame->lruRight;
						//printf("%d th trace : full -> change -> send rear	  : newstFrame->number : %d, newestFrame->vpn : %x\n",j, newestFrame->number, newestFrame->virtualPageNumber);
					}//full
					//printf("page fault\n");
				}
			}
			else {//second pagetable already created
				procTable[i].numPageFault++;
				procTable[i].num2ndLevelPageTable++;
				procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable = (pageTableEntry*)malloc(sizeof(pageTableEntry) * (1 << secondlevelBits));
				int j = 0;
				for (j = 0; j < secondlevelBits; j++) {
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[j].frameNumber = -1;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[j].level = 2;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[j].valid = 0;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[j].secondLevelPageTable = NULL;
				}

				if (oldestFrame->pid == -1) {
					oldestFrame->pid = i;
					oldestFrame->virtualPageNumber = vpn;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid = 1;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber = oldestFrame->number;
					newestFrame = newestFrame->lruRight;
					oldestFrame = oldestFrame->lruRight;
				}
				else {
					procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].valid = 0;
					procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].frameNumber = -1;
					procTable[oldestFrame->pid].firstLevelPageTable[(oldestFrame->virtualPageNumber & ((1 << 20) - 1)) >> secondlevelBits].secondLevelPageTable[(oldestFrame->virtualPageNumber) & ((1 << secondlevelBits) - 1)].level = 2;
					oldestFrame->virtualPageNumber = vpn;
					oldestFrame->pid = i;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber = oldestFrame->number;
					procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].valid = 1;
					newestFrame = newestFrame->lruRight;
					oldestFrame = oldestFrame->lruRight;
				}//가득찼을경우
				//printf("%d\n", newestFrame->number);
			}//page replacement

			procTable[i].ntraces++;
			unsigned int physicaframeindex = ((procTable[i].firstLevelPageTable[firstlevelpagenumber].secondLevelPageTable[secondlevelpagenumber].frameNumber) << 12) | offset;
			if (s_skip == false) {
				printf("Two-Level procID %d traceNumber %d virtual addr %x physical addr %x\n", i, procTable[i].ntraces, addr, physicaframeindex);
			}
			//j++;
		}
		if (flag)break;
	}


	for (i = 0; i < numProcess; i++) {
		printf("**** %s *****\n", procTable[i].traceName);
		printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
		printf("Proc %d Num of second level page tables allocated %d\n", i, procTable[i].num2ndLevelPageTable);
		printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
		printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
		assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
	}

	int j = 0;
	for (i = 0; i < numProcess; i++) {
		for (j = 0; j < firstLevelBits; j++) {
			free(procTable[i].firstLevelPageTable[j].secondLevelPageTable);
			procTable[i].firstLevelPageTable[j].secondLevelPageTable = NULL;
		}
		free(procTable[i].firstLevelPageTable);
	}


}





void invertedPageVMSim(procEntry* procTable, framePage* phyMemFrames, unsigned int nFrame) {
	unsigned int i;
	invertedPageTableEntry* invertedPageTable = (invertedPageTableEntry*)malloc(sizeof(invertedPageTableEntry) * nFrame);
	bool flag = false;
	unsigned int offset_and_op = 0x00000FFF;
	unsigned int k;
	initPhyMem(phyMemFrames, nFrame); //make physical memory 
	for (k = 0; k < nFrame; k++) {
		invertedPageTable[k].next = NULL;
		invertedPageTable[k].frameNumber = -1;
		invertedPageTable[k].pid = -1;
		invertedPageTable[k].virtualPageNumber = -1;
	}
	while (1) {
		unsigned int addr;
		char rw;
		for (i = 0; i < numProcess; i++) {
			fscanf(procTable[i].tracefp, "%x %c", &addr, &rw);
			if (feof(procTable[i].tracefp) != 0) {
				flag = true;
				break;
			}
			unsigned int offset = addr & offset_and_op;
			unsigned int vpn = addr >> PAGESIZEBITS;
			unsigned int Hashindex = (vpn + i) % nFrame; //인덱스값

			unsigned int outputframenumber = 0;
			if (invertedPageTable[Hashindex].next == NULL) {
				procTable[i].numIHTNULLAccess++;
				procTable[i].numPageFault++;

				if (oldestFrame->pid == -1) {
					oldestFrame->virtualPageNumber = vpn;
					oldestFrame->pid = i;
					invertedPageTable[Hashindex].next = (invertedPageTableEntry*)malloc(sizeof(invertedPageTableEntry));
					invertedPageTable[Hashindex].next->pid = i;
					invertedPageTable[Hashindex].next->frameNumber = oldestFrame->number;
					invertedPageTable[Hashindex].next->virtualPageNumber = oldestFrame->virtualPageNumber;
					invertedPageTable[Hashindex].next->next = NULL; //이게중요한듯
					newestFrame = newestFrame->lruRight;
					oldestFrame = oldestFrame->lruRight;
					outputframenumber = invertedPageTable[Hashindex].next->frameNumber;
				}//가득찬게아닐경우
				else {
					invertedPageTableEntry* current = invertedPageTable[(oldestFrame->virtualPageNumber + oldestFrame->pid) % nFrame].next;
					invertedPageTableEntry* prev = &invertedPageTable[(oldestFrame->virtualPageNumber + oldestFrame->pid) % nFrame];
					unsigned int todeletevirtualpagenumber = oldestFrame->virtualPageNumber;//virtualpagenumber가 유일하게 식별된다.
					unsigned int todeletepid = oldestFrame->pid;
					while (current!=NULL) {
						procTable[i].numIHTConflictAccess++;
						if (current->virtualPageNumber == todeletevirtualpagenumber && current->pid==todeletepid) {							
								prev->next = current->next;
								free(current);
								current = NULL;
								break;
						}
						else {
							prev = current;
							current = current->next;
						}
					}

					oldestFrame->pid = i;
					oldestFrame->virtualPageNumber = vpn; //적재하고
					invertedPageTable[Hashindex].next = (invertedPageTableEntry*)malloc(sizeof(invertedPageTableEntry));
					invertedPageTable[Hashindex].next->pid = i;
					invertedPageTable[Hashindex].next->frameNumber = oldestFrame->number;
					invertedPageTable[Hashindex].next->virtualPageNumber = oldestFrame->virtualPageNumber;
					invertedPageTable[Hashindex].next->next = NULL;
					newestFrame = newestFrame->lruRight;
					oldestFrame = oldestFrame->lruRight;//한바퀴돌려
					outputframenumber = newestFrame->number;

				}//가득찬경우
			}
			else {//인덱스로 접근했을때 next가 널이아닌경우라면 이미 링크드리스트가생성이되어있다는소리이다.
				procTable[i].numIHTNonNULLAcess++;
				invertedPageTableEntry* current = invertedPageTable[Hashindex].next;
				while (1) {
					procTable[i].numIHTConflictAccess++;


					if (current == NULL) {//링크드리스트생성이되어있는데 다돌고나서도 찾을수가없는경우
						procTable[i].numPageFault++;
						//printf("Page Fault : %d\n", procTable[i].numPageFault);
						invertedPageTableEntry* created = (invertedPageTableEntry*)malloc(sizeof(invertedPageTableEntry));
						created->next = NULL;

						if (oldestFrame->pid == -1) {
							oldestFrame->pid = i;
							oldestFrame->virtualPageNumber = vpn; //oldest에넣고
							created->next = invertedPageTable[Hashindex].next;
							invertedPageTable[Hashindex].next = created;
							created->frameNumber = oldestFrame->number;
							created->virtualPageNumber = oldestFrame->virtualPageNumber;
							created->pid = i;//새로생성한거에다 집어넣고
							newestFrame = newestFrame->lruRight;
							oldestFrame = oldestFrame->lruRight;
							outputframenumber = newestFrame->number;

						}//가득차지않은경우
						else {//피지컬메모리가가득찬경우
							invertedPageTableEntry* current = invertedPageTable[(oldestFrame->virtualPageNumber + oldestFrame->pid) % nFrame].next;
							invertedPageTableEntry* prev = &invertedPageTable[(oldestFrame->virtualPageNumber + oldestFrame->pid) % nFrame];
							unsigned int todeletevirtualpagenumber = oldestFrame->virtualPageNumber;
							unsigned int todeletepid = oldestFrame->pid;
							while (current!=NULL) {
								procTable[i].numIHTConflictAccess++;
								//printf("ConflicAceess : %d\n", procTable[i].numIHTConflictAccess);
								if (current->virtualPageNumber == todeletevirtualpagenumber && current->pid==todeletepid) {
										prev->next = current->next;
										free(current);
										current = NULL;
										break;
								}
								else {
									prev = current;
									current = current->next;
								}
							}//노드없애는과정 가득찼을때

							oldestFrame->pid = i;
							oldestFrame->virtualPageNumber = vpn; //oldest에넣고


							created->frameNumber = oldestFrame->number;
							created->virtualPageNumber = oldestFrame->virtualPageNumber;
							created->pid = i;//새로생성한거에다 집어넣고

							created->next = invertedPageTable[Hashindex].next;
							invertedPageTable[Hashindex].next = created;
							

							newestFrame = newestFrame->lruRight;
							oldestFrame = oldestFrame->lruRight;//회전시키기
							outputframenumber = newestFrame->number;
						}
						break;
					}

					else if (current->virtualPageNumber == vpn && current->pid == i) { //phyMemFrames[invertedPageTable[Hashindex].next->frameNumber].virtualPageNumber

						procTable[i].numPageHit++;

						if (&phyMemFrames[current->frameNumber] == newestFrame) {
							//그냥멈춰있어야함	
						}
						else if (&phyMemFrames[current->frameNumber] == oldestFrame) {
							newestFrame = newestFrame->lruRight;
							oldestFrame = oldestFrame->lruRight;
						}
						else {
							phyMemFrames[current->frameNumber].lruLeft->lruRight = phyMemFrames[current->frameNumber].lruRight;
							phyMemFrames[current->frameNumber].lruRight->lruLeft = phyMemFrames[current->frameNumber].lruLeft;
							newestFrame->lruRight = &phyMemFrames[current->frameNumber];
							phyMemFrames[current->frameNumber].lruLeft = newestFrame;
							newestFrame = newestFrame->lruRight;
							newestFrame->lruRight = oldestFrame;
							oldestFrame->lruLeft = newestFrame;
						}
						outputframenumber = newestFrame->number;
						break;
					}
					else {
						current = current->next;
					}
				}
			}

			procTable[i].ntraces++;
			outputframenumber = (outputframenumber << 12);

			if (s_skip == false) {
				printf("IHT procID %d traceNumber %d virtual addr %x physical addr %x\n", i, procTable[i].ntraces, addr, outputframenumber | offset);
			}

		}

		if (flag)break;
	}

	for (i = 0; i < numProcess; i++) {
		printf("**** %s *****\n", procTable[i].traceName);
		printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
		printf("Proc %d Num of Inverted Hash Table Access Conflicts %d\n", i, procTable[i].numIHTConflictAccess);
		printf("Proc %d Num of Empty Inverted Hash Table Access %d\n", i, procTable[i].numIHTNULLAccess);
		printf("Proc %d Num of Non-Empty Inverted Hash Table Access %d\n", i, procTable[i].numIHTNonNULLAcess);
		printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
		printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
		assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
		assert(procTable[i].numIHTNULLAccess + procTable[i].numIHTNonNULLAcess == procTable[i].ntraces);
	}
}



int main(int argc, char* argv[]) {
	int i;


	if (argv[1][0] != '-') {//아닌경우 니깐 생략을한것임
		s_skip = true;
		simtype = atoi(argv[1]);
		firstLevelBits = atoi(argv[2]);
	}
	else {
		simtype = atoi(argv[2]);
		firstLevelBits = atoi(argv[3]);
	}

	if (argc < 5) {
		printf("Usage : %s [-s] firstLevelBits PhysicalMemorySizeBits TraceFileNames\n", argv[0]); exit(1);
	}
	int j;

	if (s_skip == true) {
		phyMemSizeBits = atoi(argv[3]);
		numProcess = argc - 4;
		j = 4;
	}
	else {
		phyMemSizeBits = atoi(argv[4]);
		numProcess = argc - 5;
		j = 5;
	}

	if (phyMemSizeBits < PAGESIZEBITS) {
		printf("PhysicalMemorySizeBits %d should be larger than PageSizeBits %d\n", phyMemSizeBits, PAGESIZEBITS); exit(1);
	}
	if (VIRTUALADDRBITS - PAGESIZEBITS - firstLevelBits <= 0) {
		printf("firstLevelBits %d is too Big for the 2nd level page system\n", firstLevelBits); exit(1);
	}

	// initialize procTable for memory simulations

	for (i = 0; i < numProcess; i++) {
		// opening a tracefile for the process
		printf("process %d opening %s\n", i, argv[j + i]);
	}


	unsigned int nFrame = (1 << (phyMemSizeBits - PAGESIZEBITS)); assert(nFrame > 0);
	printf("\nNum of Frames %d Physical Memory Size %ld bytes\n", nFrame, (1L << phyMemSizeBits)); //여기문제인듯

	//initialize procTable for the simulation
	procEntry* procTable;
	framePage* phyMem;
	pageTableEntry* pagetable;
	//make physical memory 


	if (simtype == 0 || simtype == 3) {
		procTable = (procEntry*)malloc(sizeof(procEntry) * numProcess);
		phyMem = (framePage*)malloc(sizeof(framePage) * nFrame);

		initPhyMem(phyMem, nFrame);
		for (i = 0; i < numProcess; i++) {
			// initialize procTable fields
			// rewind tracefiles
			procTable[i].pid = i;
			procTable[i].traceName = argv[j + i];
			procTable[i].tracefp = fopen(procTable[i].traceName, "r");
			procTable[i].ntraces = 0;
			unsigned int pagetablesize = (1 << (VIRTUALADDRBITS - PAGESIZEBITS));

			procTable[i].firstLevelPageTable = (pageTableEntry*)malloc(sizeof(pageTableEntry) * pagetablesize);
			unsigned int k;
			for (k = 0; k < pagetablesize; k++) {
				procTable[i].firstLevelPageTable[k].level = 1;
				procTable[i].firstLevelPageTable[k].valid = 0;
				procTable[i].firstLevelPageTable[k].frameNumber = -1;
				procTable[i].firstLevelPageTable[k].secondLevelPageTable = NULL;
			}
			procTable[i].numPageFault = 0;
			procTable[i].numPageHit = 0;

			procTable[i].num2ndLevelPageTable = 0;
			procTable[i].numIHTConflictAccess = 0;
			procTable[i].numIHTNonNULLAcess = 0;
			procTable[i].numIHTNULLAccess = 0;
			rewind(procTable[i].tracefp);
		}
		printf("=============================================================\n");
		printf("The One-Level Page Table with FIFO Memory Simulation Starts .....\n");
		printf("=============================================================\n");
		oneLevelVMSimFIFO(procTable, phyMem);
		free(procTable);
		free(phyMem);
		//free(pagetable);
		procTable = NULL;
		phyMem = NULL;
		pagetable = NULL;

		procTable = (procEntry*)malloc(sizeof(procEntry) * numProcess);
		phyMem = (framePage*)malloc(sizeof(framePage) * nFrame);
		initPhyMem(phyMem, nFrame); //make physical memory 
		for (i = 0; i < numProcess; i++) {
			// initialize procTable fields
			// rewind tracefiles
			procTable[i].pid = i;
			procTable[i].traceName = argv[j + i];
			procTable[i].tracefp = fopen(procTable[i].traceName, "r");
			procTable[i].ntraces = 0;
			unsigned int pagetablesize = (1 << (VIRTUALADDRBITS - PAGESIZEBITS));
			//pageTableEntry* pagetable = (pageTableEntry*)malloc(sizeof(pageTableEntry) * pagetablesize);
			procTable[i].firstLevelPageTable = (pageTableEntry*)malloc(sizeof(pageTableEntry) * pagetablesize);
			unsigned int k;
			for (k = 0; k < pagetablesize; k++) {
				procTable[i].firstLevelPageTable[k].level = 1;
				procTable[i].firstLevelPageTable[k].valid = 0;
				procTable[i].firstLevelPageTable[k].frameNumber = -1;
				procTable[i].firstLevelPageTable[k].secondLevelPageTable = NULL;
			}
			procTable[i].numPageFault = 0;
			procTable[i].numPageHit = 0;

			procTable[i].num2ndLevelPageTable = 0;
			procTable[i].numIHTConflictAccess = 0;
			procTable[i].numIHTNonNULLAcess = 0;
			procTable[i].numIHTNULLAccess = 0;
			rewind(procTable[i].tracefp);
		}
		printf("=============================================================\n");
		printf("The One-Level Page Table with LRU Memory Simulation Starts .....\n");
		printf("=============================================================\n");
		oneLevelVMSimLRU(procTable, phyMem);
		free(procTable);
		free(phyMem);
		//free(pagetable);
		procTable = NULL;
		phyMem = NULL;
		pagetable = NULL;
	}


	if (simtype == 1 || simtype == 3) {
		procTable = (procEntry*)malloc(sizeof(procEntry) * numProcess);
		phyMem = (framePage*)malloc(sizeof(framePage) * nFrame);
		initPhyMem(phyMem, nFrame);


		for (i = 0; i < numProcess; i++) {
			// initialize procTable fields
			// rewind tracefiles
			procTable[i].pid = i;
			procTable[i].traceName = argv[j + i];
			procTable[i].tracefp = fopen(procTable[i].traceName, "r");
			procTable[i].ntraces = 0;
			unsigned int pagetablesize = (1 << firstLevelBits);
			//pagetable = (pageTableEntry*)malloc(sizeof(pageTableEntry) * pagetablesize);
			procTable[i].firstLevelPageTable = (pageTableEntry*)malloc(sizeof(pageTableEntry) * pagetablesize);
			unsigned int k;
			for (k = 0; k < pagetablesize; k++) {
				procTable[i].firstLevelPageTable[k].level = 1;
				procTable[i].firstLevelPageTable[k].valid = 0;
				procTable[i].firstLevelPageTable[k].secondLevelPageTable = NULL;
				procTable[i].firstLevelPageTable[k].frameNumber = -1;
			}
			procTable[i].numPageFault = 0;
			procTable[i].numPageHit = 0;

			procTable[i].num2ndLevelPageTable = 0;
			procTable[i].numIHTConflictAccess = 0;
			procTable[i].numIHTNonNULLAcess = 0;
			procTable[i].numIHTNULLAccess = 0;
			rewind(procTable[i].tracefp);
		}
		printf("=============================================================\n");
		printf("The Two-Level Page Table Memory Simulation Starts .....\n");
		printf("=============================================================\n");
		twoLevelVMSim(procTable, phyMem);
		free(procTable);
		free(phyMem);
		//free(pagetable);
		procTable = NULL;
		phyMem = NULL;
		pagetable = NULL;
	}

	if (simtype == 2 || simtype == 3) {
		// initialize procTable for the simulation
		procTable = (procEntry*)malloc(sizeof(procEntry) * numProcess);
		phyMem = (framePage*)malloc(sizeof(framePage) * nFrame);
		initPhyMem(phyMem, nFrame); //make physical memory 

		for (i = 0; i < numProcess; i++) {
			// initialize procTable fields
			// rewind tracefiles
			procTable[i].pid = i;
			procTable[i].traceName = argv[j + i];
			procTable[i].tracefp = fopen(procTable[i].traceName, "r");
			procTable[i].ntraces = 0;

			procTable[i].numPageFault = 0;
			procTable[i].numPageHit = 0;

			procTable[i].num2ndLevelPageTable = 0;
			procTable[i].numIHTConflictAccess = 0;
			procTable[i].numIHTNonNULLAcess = 0;
			procTable[i].numIHTNULLAccess = 0;
			rewind(procTable[i].tracefp);

		}
		printf("=============================================================\n");
		printf("The Inverted Page Table Memory Simulation Starts .....\n");
		printf("=============================================================\n");
		invertedPageVMSim(procTable, phyMem, nFrame);

	}

	return(0);
}