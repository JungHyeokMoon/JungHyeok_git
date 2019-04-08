#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include<iomanip>
using namespace std;

clock_t exchangetime[3] = { 0 };
clock_t mergetime[4][3] = { 0 };
clock_t quicktime1[3] = { 0 };
clock_t quicktime2[4][3] = { 0 };

void printresult(int *size1, int *size2) {
	cout << setw(30) << "" << setw(6) << "N=" << setw(7) << size1[0] << setw(6) << "N=" << setw(7) << size1[1] << setw(6) << "N=" << setw(7) << size1[2] << endl;
	cout << setw(15) << "" << setw(15) << "Exchange Sort" << setw(13) << exchangetime[0] << setw(13) << exchangetime[1] << setw(13) << exchangetime[2] << endl;
	cout << setw(15) << "" << setw(15) << "Quick sort" << setw(13) << quicktime1[0] << setw(13) << quicktime1[1] << setw(13) << quicktime1[2] << endl << endl;

	cout << setw(30) << "" << setw(6) << "N=" << setw(7) << size2[0] << setw(6) << "N=" << setw(7) << size2[1] << setw(6) << "N=" << setw(7) << size2[2] << endl;
	cout << setw(15) << "" << setw(15) << "data1" << setw(13) << mergetime[0][0] << setw(13) << mergetime[0][1] << setw(13) << mergetime[0][2] << endl;
	cout << setw(15) << "Merge sort" << setw(15) << "data2" << setw(13) << mergetime[1][0] << setw(13) << mergetime[1][1] << setw(13) << mergetime[1][2] << endl;
	cout << setw(15) << "" << setw(15) << "data3" << setw(13) << mergetime[2][0] << setw(13) << mergetime[2][1] << setw(13) << mergetime[2][2] << endl;
	cout << setw(15) << "" << setw(15) << "average" << setw(13) << mergetime[3][0] << setw(13) << mergetime[3][1] << setw(13) << mergetime[3][2] << endl << endl;

	
	cout << setw(15) << "" << setw(15) << "data1" << setw(13) << quicktime2[0][0] << setw(13) << quicktime2[0][1] << setw(13) << quicktime2[0][2] << endl;
	cout << setw(15) << "Quick sort" << setw(15) << "data2" << setw(13) << quicktime2[1][0] << setw(13) << quicktime2[1][1] << setw(13) << quicktime2[1][2] << endl;
	cout << setw(15) << "" << setw(15) << "data3" << setw(13) << quicktime2[2][0] << setw(13) << quicktime2[2][1] << setw(13) << quicktime2[2][2] << endl;
	cout << setw(15) << "" << setw(15) << "average" << setw(13) << quicktime2[3][0] << setw(13) << quicktime2[3][1] << setw(13) << quicktime2[3][2] << endl;



}


void exchangesort(int* ary, int size) {
	for (int i = 1; i <= size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (ary[j] < ary[i]) {
				int temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}


void Partition(int low, int high, int *pivot, int* ary) {
	int i, j;
	int item = ary[low];
	j = low;

	for (i = low + 1; i <= high; i++) {
		if (ary[i] < item) {
			j++;
			int temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
	}
	*pivot = j;
	int temp = ary[low];
	ary[low] = ary[j];
	ary[j] = temp;
}

void Quick_sort(int low, int high, int* ary) {
	int pivot;
	if (high > low) {
		Partition(low, high, &pivot, ary);
		Quick_sort(low, pivot - 1, ary);
		Quick_sort(pivot + 1, high, ary);
	}
}



void merge2(int *arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = 0;
	int * mergetemp = new int[end - start + 1];

	
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			mergetemp[k] = arr[i];
			i++;
		}
		else {
			mergetemp[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		while (j <= end) {
			mergetemp[k++] = arr[j++];
		}
	}
	else {
		while (i <= mid) {
			mergetemp[k++] = arr[i++];
		}
	}
	for (k = 0; k <= (end - start); k++) {
		arr[start + k] = mergetemp[k];
	}
	delete[] mergetemp;
} //합병정렬

void mergesort2(int *arr, int start, int end) {
	int mid ;
	if (start < end) {
		mid = ((start + end) / 2);
		mergesort2(arr, start,  mid);
		mergesort2(arr, mid + 1, end);
		merge2(arr, start, mid, end);
	}
}

void insertsortdata(int *arr1, int *arr2, int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = i;
		arr2[i] = i;
	}
}

void insertRandomdata(int *arr1, int *arr2, int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = rand() % size;
		arr2[i] = rand() % size;
	}
}
int main() {
	int size1[3], size2[3];
	FILE *f = fopen("input.txt", "r");
	fscanf(f, "%d %d %d", &size1[0], &size1[1], &size1[2]);
	fscanf(f, "%d %d %d", &size2[0], &size2[1], &size2[2]);
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++) {
		int *asarr1 = new int[size1[i]];
		int *asarr2 = new int[size1[i]];

		insertsortdata(asarr1, asarr2, size1[i]);
		
		clock_t time = clock();
		exchangesort(asarr1, size1[i] );
		exchangetime[i] = clock()-time;

		time = clock();
		Quick_sort(0,size1[i]-1,asarr2);
		quicktime1[i] = clock()-time;
		
		delete[] asarr1;
		delete[] asarr2;
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int *randarr1 = new int[size2[j]];
			int *randarr2 = new int[size2[j]];

			insertRandomdata(randarr1, randarr2, size2[j]);
			clock_t time = clock();
			mergesort2(randarr1, 0, size2[j] - 1);
			mergetime[i][j] = clock()-time;

			time = clock();
			Quick_sort(0,size2[j]-1,randarr2);
			quicktime2[i][j] = clock()-time;

			delete[]randarr1;
			delete[]randarr2;
		}
	}
	int i = 0, j = 0;
	for ( j = 0; j < 3; j++) {
		for (i = 0; i < 3; i++) {
			mergetime[3][j] += mergetime[i][j];
			quicktime2[3][j] += quicktime2[i][j];
		}
		mergetime[3][j] = (mergetime[3][j]) / 3;
		quicktime2[3][j] = (quicktime2[3][j]) / 3;
	}

	printresult(size1, size2);

	fclose(f);
}
