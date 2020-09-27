// Submit Year:2019
// Class : Operating System
// Simple FIle System
// Student Name :MoonJungHyeok
// Student Number :B511057
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* optional */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/***********/

#include "sfs_types.h"
#include "sfs_func.h"
#include "sfs_disk.h"
#include "sfs.h"

void dump_directory();

/* BIT operation Macros */
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

static struct sfs_super spb;	// superblock
static struct sfs_dir sd_cwd = { SFS_NOINO }; // current working directory

void error_message(const char* message, const char* path, int error_code) {
	switch (error_code) {
	case -1:
		printf("%s: %s: No such file or directory\n", message, path); return;
	case -2:
		printf("%s: %s: Not a directory\n", message, path); return;
	case -3:
		printf("%s: %s: Directory full\n", message, path); return;
	case -4:
		printf("%s: %s: No block available\n", message, path); return;
	case -5:
		printf("%s: %s: Not a directory\n", message, path); return;
	case -6:
		printf("%s: %s: Already exists\n", message, path); return;
	case -7:
		printf("%s: %s: Directory not empty\n", message, path); return;
	case -8:
		printf("%s: %s: Invalid argument\n", message, path); return;
	case -9:
		printf("%s: %s: Is a directory\n", message, path); return;
	case -10:
		printf("%s: %s: Is not a file\n", message, path); return;
	default:
		printf("unknown error code\n");
		return;
	}
}

void sfs_mount(const char* path)
{
	if (sd_cwd.sfd_ino != SFS_NOINO)
	{
		//umount
		disk_close();
		printf("%s, unmounted\n", spb.sp_volname);
		bzero(&spb, sizeof(struct sfs_super));
		sd_cwd.sfd_ino = SFS_NOINO;
	}

	printf("Disk image: %s\n", path);

	disk_open(path);
	disk_read(&spb, SFS_SB_LOCATION);

	printf("Superblock magic: %x\n", spb.sp_magic);

	assert(spb.sp_magic == SFS_MAGIC);

	printf("Number of blocks: %d\n", spb.sp_nblocks);
	printf("Volume name: %s\n", spb.sp_volname);
	printf("%s, mounted\n", spb.sp_volname);

	sd_cwd.sfd_ino = 1;		//init at root
	sd_cwd.sfd_name[0] = '/';
	sd_cwd.sfd_name[1] = '\0';
}

void sfs_umount() {

	if (sd_cwd.sfd_ino != SFS_NOINO)
	{
		//umount
		disk_close();
		printf("%s, unmounted\n", spb.sp_volname);
		bzero(&spb, sizeof(struct sfs_super));
		sd_cwd.sfd_ino = SFS_NOINO;
	}
}


u_int32_t firstfreeblocksearch() {
	u_int32_t firstfreeblock = -1;
	int size = spb.sp_nblocks / 8;  //(spb.sp_nblocks / 8);
	int bitblocks = SFS_BITBLOCKS(spb.sp_nblocks);
	int k = 0;
	u_int8_t* bitmap = (u_int8_t*)malloc(sizeof(u_int8_t) * 512);
	int itersize = 0;
	int flag = 0;
	for (k = 0; k < bitblocks; k++) {
		if (k == bitblocks - 1) {
			itersize = size % 512;
		}
		else {
			itersize = 512;
		}
		disk_read(bitmap, SFS_MAP_LOCATION + k);
		int i = 0;
		for (i = 0; i < itersize; i++) {
			u_int8_t temp = bitmap[i];
			int j = 0;
			for (j = 0; j < CHAR_BIT; j++) {
				if (!BIT_CHECK(bitmap[i], j)) {
					flag = 1;
					firstfreeblock = k * 4096 + i * 8 + j;
					break;
				}
			}
			if (flag)break;
		}
		if (flag)break;
	}
	free(bitmap);
	return firstfreeblock;
}//�а����ִ°ű���
void checkbitmap(u_int32_t firstfreeblock) {
	u_int32_t temp = firstfreeblock;
	//firstblock�� ��Ʈ�ʿ��� �ٽ� 0���� ������ִ��۾����ؾ���
	int k = temp / (SFS_BLOCKSIZE * CHAR_BIT);
	temp = temp % 4096;
	int i = temp / CHAR_BIT;
	int j = temp % CHAR_BIT;
	u_int8_t* bitmap = (u_int8_t*)malloc(sizeof(u_int8_t) * 512);
	disk_read(bitmap, SFS_MAP_LOCATION + k);
	BIT_SET(bitmap[i], j);
	disk_write(bitmap, SFS_MAP_LOCATION + k);
	free(bitmap);
	return;
}

void removebitmap(u_int32_t firstfreeblock) {
	u_int32_t temp = firstfreeblock;
	//firstblock�� ��Ʈ�ʿ��� �ٽ� 0���� ������ִ��۾����ؾ���
	int k = temp / (SFS_BLOCKSIZE * CHAR_BIT);
	temp = temp % 4096;
	int i = temp / CHAR_BIT;
	int j = temp % CHAR_BIT;
	u_int8_t* bitmap = (u_int8_t*)malloc(sizeof(u_int8_t) * 512);
	disk_read(bitmap, SFS_MAP_LOCATION + k);
	BIT_CLEAR(bitmap[i], j);
	disk_write(bitmap, SFS_MAP_LOCATION + k);
	free(bitmap);
	return;
}
int trueorfalsebit(u_int32_t blocknum) {
	u_int32_t temp = blocknum;
	int k = temp / (SFS_BLOCKSIZE * CHAR_BIT);
	temp = temp % 4096;
	int i = temp / CHAR_BIT;
	int j = temp % CHAR_BIT;
	u_int8_t* bitmap = (u_int8_t*)malloc(sizeof(u_int8_t) * 512);
	disk_read(bitmap, SFS_MAP_LOCATION + k);
	if (BIT_CHECK(bitmap[i], j)) {
		return 1;
	} //1�̸� ���� 1
	else {
		return 0;
	}
}
void sfs_touch(const char* path)
{
	const char command[] = "touch";
	struct sfs_inode si;
	disk_read(&si, sd_cwd.sfd_ino);

	assert(si.sfi_type == SFS_TYPE_DIR);
	
	if ((si.sfi_size)/sizeof(struct sfs_dir) == SFS_DENTRYPERBLOCK*SFS_NDIRECT) {
		int i = 0;
		for (i = 0; i < SFS_NDIRECT; i++) {
			struct sfs_dir sd[SFS_DENTRYPERBLOCK];
			disk_read(sd, si.sfi_direct[i]);
			int j = 0;
			for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
				if (!strcmp(sd[j].sfd_name, path)) {
					error_message(command, path, -6); //ALREADY EXISTS
					return;
				}
			}

		}
		error_message(command, path, -3); //���丮 FULL
		return;
	} //��á����� ,�̸�

	int i = 0;
	for (i = 0; i < SFS_NDIRECT; i++) {
		int j = 0;
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, path)) {
				error_message(command, path, -6); //ALREADY EXISTS
				return;
			}
		}
	} //�̸�üũ


	for (i = 0; i < SFS_NDIRECT; i++) {
		if (si.sfi_direct[i] == 0) {
			int firstfreeblock = firstfreeblocksearch();
			if (firstfreeblock == -1) {
				error_message(command, path, -4);
				return;
			}
			checkbitmap(firstfreeblock);
			int secondfreeblock = firstfreeblocksearch();
			if (secondfreeblock == -1) {
				removebitmap(firstfreeblock);
				error_message(command, path, -4);
				return;
			}
			checkbitmap(secondfreeblock);
			si.sfi_direct[i] = firstfreeblock;
			struct sfs_dir sd[SFS_DENTRYPERBLOCK];
			sd[0].sfd_ino = secondfreeblock;
			strncpy(sd[0].sfd_name, path, SFS_NAMELEN);
			disk_write(sd, si.sfi_direct[0]);
			si.sfi_size += sizeof(struct sfs_dir);
			disk_write(&si, sd_cwd.sfd_ino);

			struct sfs_inode newbie;
			bzero(&newbie, SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
			newbie.sfi_size = 0;
			newbie.sfi_type = SFS_TYPE_FILE;
			disk_write(&newbie, firstfreeblock);
			return;
			
		}
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		int j = 0;
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (sd[j].sfd_ino == SFS_NOINO) {
				int firstfreeblock = firstfreeblocksearch();
				if (firstfreeblock == -1) {
					error_message(command, path, -4);
					return;
				}
				checkbitmap(firstfreeblock);
				sd[j].sfd_ino = firstfreeblock;
				strncpy(sd[j].sfd_name, path, SFS_NAMELEN);
				disk_write(sd, si.sfi_direct[i]);
				si.sfi_size += sizeof(struct sfs_dir);
				disk_write(&si, sd_cwd.sfd_ino);

				struct sfs_inode newbie;
				bzero(&newbie, SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
				newbie.sfi_size = 0;
				newbie.sfi_type = SFS_TYPE_FILE;
				disk_write(&newbie, firstfreeblock);
				return;
			}
		}
	}
}



void sfs_cd(const char* path)
{
	//u_int32_t original = sd_cwd.sfd_ino;// original currentory block inode number 
	if (path == NULL) {
		sd_cwd.sfd_ino = SFS_ROOT_LOCATION;
		strncpy(sd_cwd.sfd_name, ".", SFS_NAMELEN);
		return;
	}
	else {
		struct sfs_inode si;
		disk_read(&si, sd_cwd.sfd_ino);
		int i = 0;
		
		const char command[] = "cd";
		for (i = 0; i <SFS_NDIRECT; i++) {
			
			struct sfs_dir sd[SFS_DENTRYPERBLOCK];
			disk_read(sd, si.sfi_direct[i]);
			int j = 0;
			for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
				if (!strcmp(sd[j].sfd_name, path)) { //name==path -> file or directory
					//flag = 1;
					struct sfs_inode readfor_cd;
					disk_read(&readfor_cd, sd[j].sfd_ino); //�а�
					if (readfor_cd.sfi_type == SFS_TYPE_INVAL) {
						error_message(command, path, -2);
						return;
					}
					else if (readfor_cd.sfi_type == SFS_TYPE_FILE) {
						error_message(command, path, -2);
						return;
					}
					else if (readfor_cd.sfi_type == SFS_TYPE_DIR) {
						sd_cwd.sfd_ino = sd[j].sfd_ino;
						strncpy(sd_cwd.sfd_name, sd[j].sfd_name, SFS_NAMELEN);
						return;
					}	
				}
			}
		}
		error_message(command, path, -1);
		return;

	}
}

void sfs_ls(const char* path)
{
	u_int32_t original = sd_cwd.sfd_ino;// original currentory block inode number 
	
	if (path == NULL) { //������丮 ���� �� �о��༭ �����ָ�ȴ� sd_cwd <=> current directory //printf("current directory\n");
		struct sfs_inode si;
		disk_read(&si, sd_cwd.sfd_ino); //������丮�о���
		//printf("indirect index : %d\n", si.sfi_indirect);
		int i = 0;
		for (i = 0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) { //���̳�� �����ͺ��� �ٵ��°Ծƴ�
				break;
			}
			struct sfs_dir sd[SFS_DENTRYPERBLOCK];
			disk_read(sd, si.sfi_direct[i]);
			int j = 0;
			for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
				struct sfs_inode readfor_ls;
				disk_read(&readfor_ls, sd[j].sfd_ino); //�а� 
				if (readfor_ls.sfi_type == SFS_TYPE_FILE) { //�����̸� �׳�
					printf("%s\t", sd[j].sfd_name);
				}
				else if (readfor_ls.sfi_type == SFS_TYPE_DIR) { //directory�� / �ٿ���
					printf("%s/\t", sd[j].sfd_name);
				}
			}
		}
		printf("\n");
	}
	else { // if not current directory -> read everything for path //if file -> output->filename, directory->directory ���� �ȿ��ִ°͵� 
	  //�ڿ� ��ΰ� ���µ� ������ error �޼�������ؾ���
		struct sfs_inode si;
		disk_read(&si, sd_cwd.sfd_ino);
		int i = 0;
		int flag = 0; // �ڿ����� ã�Ҵ��� ��ã�Ҵ��� 0�϶��� ��ã�Ұ� 1�϶��� ã����
		const char command[] = "ls";

		for (i = 0; i < SFS_NDIRECT; i++) {
			struct sfs_dir sd[SFS_DENTRYPERBLOCK];
			disk_read(sd, si.sfi_direct[i]);
			int j = 0;
			for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
				if (!strcmp(sd[j].sfd_name, path)) { // 0�̸� ���ٴ¼Ҹ��ϱ� �������� �������� ������ ���ָ�ǰ�
					struct sfs_inode readfor_ls;
					disk_read(&readfor_ls, sd[j].sfd_ino); //�а� 
					//flag = 1;
					if (readfor_ls.sfi_type == SFS_TYPE_FILE) { //�����̸� �׳�
						
						printf("%s\n", sd[j].sfd_name);
						return;
					}
					else if (readfor_ls.sfi_type == SFS_TYPE_DIR) { //directory�� / �ٿ���
						
						sd_cwd.sfd_ino = sd[j].sfd_ino;
						sfs_ls(NULL);
						sd_cwd.sfd_ino = original; //��������� ®�� ������ �ٽ� ���ƿ;��Ѵ�.
						return;
					}
				}
			}
		}
		error_message(command, path, -1);
		return; //��ã�����ϱ�
	}
}

void sfs_mkdir(const char* org_path)
{
	const char command[] = "mkdir";
	struct sfs_inode si;
	disk_read(&si, sd_cwd.sfd_ino);
	
	int i = 0;
	for (i = 0; i < SFS_NDIRECT; i++) {
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		int j = 0;
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, org_path)) {//�������
				error_message(command, org_path, -6);
				return;
			}
			
		}
	} //�̸������� ó��
	if (si.sfi_size/(sizeof(struct sfs_dir)) == SFS_DENTRYPERBLOCK * SFS_NDIRECT) { //120�ΰ��
		error_message(command, org_path, -3);
		return;
	} //���丮���������


	for (i = 0; i < SFS_NDIRECT; i++) {
		if (si.sfi_direct[i] == 0) {
			int firstfreeblock = firstfreeblocksearch();
			if (firstfreeblock == -1) {
				error_message(command, org_path, -4);
				return;
			}
			checkbitmap(firstfreeblock);
			int secondfreeblock = firstfreeblocksearch();
			if (secondfreeblock == -1) {
				removebitmap(firstfreeblock);
				error_message(command, org_path, -4);
				return;
			}
			checkbitmap(secondfreeblock);
			int thirdfreeblock = firstfreeblocksearch();
			if (thirdfreeblock == -1) {
				removebitmap(firstfreeblock);
				removebitmap(secondfreeblock);
				error_message(command, org_path, -4);
				return;
			}//���̻��Ҵ��Һ���������� ����ó��
			checkbitmap(thirdfreeblock); //

			si.sfi_direct[i] = firstfreeblock;
			struct sfs_dir sd[SFS_DENTRYPERBLOCK];
			sd[0].sfd_ino = secondfreeblock;
			strncpy(sd[0].sfd_name, org_path, SFS_NAMELEN);
			disk_write(sd, si.sfi_direct[i]);
			si.sfi_size += sizeof(struct sfs_dir);
			disk_write(&si, sd_cwd.sfd_ino);

			struct sfs_inode newbie;
			bzero(&newbie, SFS_BLOCKSIZE);
			newbie.sfi_size = (sizeof(struct sfs_dir)) * 2;// . ..���ؼ�
			newbie.sfi_type = SFS_TYPE_DIR;
			newbie.sfi_direct[0] = thirdfreeblock; //�����丮�� ���� ���̳�� �Ҵ��Ǳ⺻���� �ι�° ������� ���̳�忡 �����ͺ������� �Ҵ��ؾ��ϴϱ�

			struct sfs_dir newbiedirentry[SFS_DENTRYPERBLOCK];
			int k = 0;
			for (k = 0; k < SFS_DENTRYPERBLOCK; k++) {
				bzero(&newbiedirentry[k], sizeof(struct sfs_dir));
			}

			newbiedirentry[0].sfd_ino = secondfreeblock;
			strncpy(newbiedirentry[0].sfd_name, ".", SFS_NAMELEN);
			newbiedirentry[1].sfd_ino = sd_cwd.sfd_ino;
			strncpy(newbiedirentry[1].sfd_name, "..", SFS_NAMELEN);

			disk_write(newbiedirentry, newbie.sfi_direct[0]);//���丮��Ʈ���� �����Ҵ��� ���̳�� 0��° ndirect������
			disk_write(&newbie, secondfreeblock); //�����丮�� ���� ���̳�带 ��ũ������
			return;
		}
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		int j = 0;
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (sd[j].sfd_ino == 0) {//���丮��Ʈ������ִ°��
				u_int32_t firstfreeblock = firstfreeblocksearch();
				if (firstfreeblock == -1) {
					error_message(command, org_path, -4);
					return;
				}
				checkbitmap(firstfreeblock);
				
				u_int32_t secondfreeblock = firstfreeblocksearch();
				if (secondfreeblock == -1) {
					removebitmap(firstfreeblock);
					error_message(command, org_path, -4);
					return;
				}
				checkbitmap(secondfreeblock);
				
				sd[j].sfd_ino = firstfreeblock;
				strncpy(sd[j].sfd_name, org_path, SFS_NAMELEN);
				disk_write(sd, si.sfi_direct[i]);
				si.sfi_size += sizeof(struct sfs_dir);
				disk_write(&si, sd_cwd.sfd_ino); //�������������̷�Ʈ���� ���°�

				struct sfs_inode newbie;
				bzero(&newbie, SFS_BLOCKSIZE);
				newbie.sfi_size = (sizeof(struct sfs_dir)) * 2;// . ..���ؼ�
				newbie.sfi_type = SFS_TYPE_DIR;
				newbie.sfi_direct[0] = secondfreeblock; //�����丮�� ���� ���̳�� �Ҵ��Ǳ⺻���� �ι�° ������� ���̳�忡 �����ͺ������� �Ҵ��ؾ��ϴϱ�
				

				struct sfs_dir newbiedirentry[SFS_DENTRYPERBLOCK];
				int k = 0;
				
				for (k = 0; k < SFS_DENTRYPERBLOCK; k++) {
					bzero(&newbiedirentry[k],sizeof(struct sfs_dir));
				}

				newbiedirentry[0].sfd_ino = firstfreeblock;
				strncpy(newbiedirentry[0].sfd_name, ".", SFS_NAMELEN);
				newbiedirentry[1].sfd_ino = sd_cwd.sfd_ino;
				strncpy(newbiedirentry[1].sfd_name,".." , SFS_NAMELEN);
				disk_write(newbiedirentry, newbie.sfi_direct[0]);//���丮��Ʈ���� �����Ҵ��� ���̳�� 0��° ndirect������
				disk_write(&newbie, firstfreeblock); //�����丮�� ���� ���̳�带 ��ũ������
				
				return;
			}
		}
	}
	
	
}

void sfs_rmdir(const char* org_path)
{
	const char command[] = "rmdir";
	struct sfs_inode si;
	disk_read(&si, sd_cwd.sfd_ino);

	int i = 0;
	if (!strcmp(org_path,".")) {
		error_message(command, org_path, -8);
		return;
	}
	for (i = 0; i < SFS_NDIRECT; i++) {
		int j = 0;
		struct sfs_dir sd[SFS_DENTRYPERBLOCK]; 
		disk_read(sd, si.sfi_direct[i]);
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, org_path)) {
				struct sfs_inode filetypechek;
				disk_read(&filetypechek, sd[j].sfd_ino);


				if (filetypechek.sfi_type == SFS_TYPE_FILE) {
					error_message(command, org_path, -5);
					return;
				}//�����ΰ��
				if ((filetypechek.sfi_size) / sizeof(struct sfs_dir) != 2) {
					error_message(command, org_path, -7);
					return;
				}//��������ʴٴ¼Ҹ�
				//��������������ִ°��
				u_int32_t removeblock1 = sd[j].sfd_ino;
				sd[j].sfd_ino = SFS_NOINO;
				disk_write(sd, si.sfi_direct[i]);
				si.sfi_size -= sizeof(struct sfs_dir);
				disk_write(&si, sd_cwd.sfd_ino);
				u_int32_t removeblock2 = filetypechek.sfi_direct[0];
				removebitmap(removeblock1);
				removebitmap(removeblock2);
				return;
			}
		}
	}
	error_message(command, org_path, -1);
	//���ٴ¼Ҹ��ϱ�
}

void sfs_mv(const char* src_name, const char* dst_name) //src_name�� dst_name���� �ٲ۴�
{
	const char command[] = "mv";
	struct sfs_inode si;
	disk_read(&si, sd_cwd.sfd_ino);
	
	int i = 0;
	int flag = 0;
	for (i = 0; i < SFS_NDIRECT; i++) {
		int j = 0;
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, src_name)) { 
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}

	if (!flag) {
		error_message(command, src_name, -1);
		return;
	}//���°��
	for (i = 0; i < SFS_NDIRECT; i++) {
		int j = 0;
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, dst_name)) { //�ٲٷ����̸��� �̹��ִ°��
				error_message(command, dst_name, -6);
				return;
			}
		}
		
	}
	
	for (i = 0; i < SFS_NDIRECT; i++) {
		int j = 0;
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, src_name)) { 
				strncpy(sd[j].sfd_name, dst_name, SFS_NAMELEN);
				disk_write(sd, si.sfi_direct[i]);
				return;
			}
		}
	}
	
}


void sfs_rm(const char* path)
{
	const char command[] = "rm";
	struct sfs_inode si;
	disk_read(&si, sd_cwd.sfd_ino);
	int i = 0;
	for (i = 0; i < SFS_NDIRECT; i++) {
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		int j = 0;
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name,path)) {
				struct sfs_inode forread_si;
				disk_read(&forread_si, sd[j].sfd_ino);
				if (forread_si.sfi_type == SFS_TYPE_DIR) {
					error_message(command, path, -9);
					return;
				} //���丮�鸮��
				u_int32_t removeblock1 = sd[j].sfd_ino;
				removebitmap(removeblock1);
				sd[j].sfd_ino = SFS_NOINO;
				disk_write(sd, si.sfi_direct[i]);
				si.sfi_size -= sizeof(struct sfs_dir);
				disk_write(&si, sd_cwd.sfd_ino);//���丮�ȿ� ����°ű����ذ�
				int k = 0;
				for (k = 0; k < SFS_NDIRECT; k++) {
					if (forread_si.sfi_direct[k] != 0) {
						u_int32_t removeblock = forread_si.sfi_direct[k];
						removebitmap(removeblock);
					}
				}
				if (forread_si.sfi_indirect != 0) {
					u_int32_t indirect[SFS_DBPERIDB];
					disk_read(indirect, si.sfi_indirect);
					int j = 0;
					for (j = 0; j < SFS_DBPERIDB; j++) {

					}
				}
				return;
			}
		}
	}
	error_message(command, path, -1); //�����鸮��
}

void sfs_cpin(const char* local_path, const char* path) //local �� �� disk , path �� �ۿ��ִ°�
{
	const char command[] = "cpin";
	FILE* fp = NULL;
	fp = fopen(path, "r");
	if (fp == NULL) {
		printf("cpin: can't open %s input file\n", path);
		return;
	}
	
	struct sfs_inode si;
	disk_read(&si, sd_cwd.sfd_ino);
	if (si.sfi_indirect != 0) {
		struct sfs_inode indirect;
		disk_read(&indirect, si.sfi_indirect);

	}
	int i = 0;
	for (i = 0; i < SFS_NDIRECT; i++) {
		int j = 0;
		struct sfs_dir sd[SFS_DENTRYPERBLOCK];
		disk_read(sd, si.sfi_direct[i]);
		for (j = 0; j < SFS_DENTRYPERBLOCK; j++) {
			if (!strcmp(sd[j].sfd_name, local_path)) {
				error_message(command, local_path, -6);
				return;
			}
		}
	}
}


void dump_inode(struct sfs_inode inode) {
	int i;
	struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];

	printf("size %d type %d direct ", inode.sfi_size, inode.sfi_type);
	for (i = 0; i < SFS_NDIRECT; i++) {
		printf(" %d ", inode.sfi_direct[i]);
	}
	printf(" indirect %d", inode.sfi_indirect);
	printf("\n");

	if (inode.sfi_type == SFS_TYPE_DIR) {
		for (i = 0; i < SFS_NDIRECT; i++) {
			if (inode.sfi_direct[i] == 0) break;
			disk_read(dir_entry, inode.sfi_direct[i]);
			dump_directory(dir_entry);
		}
	}

}

void dump_directory(struct sfs_dir dir_entry[]) {
	int i;
	struct sfs_inode inode;
	for (i = 0; i < SFS_DENTRYPERBLOCK; i++) {
		printf("%d %s\n", dir_entry[i].sfd_ino, dir_entry[i].sfd_name);
		disk_read(&inode, dir_entry[i].sfd_ino);
		if (inode.sfi_type == SFS_TYPE_FILE) {
			printf("\t");
			dump_inode(inode);
		}
	}
}

void sfs_dump() {
	// dump the current directory structure
	struct sfs_inode c_inode;

	disk_read(&c_inode, sd_cwd.sfd_ino);
	printf("cwd inode %d name %s\n", sd_cwd.sfd_ino, sd_cwd.sfd_name);
	dump_inode(c_inode);
	printf("\n");

}

