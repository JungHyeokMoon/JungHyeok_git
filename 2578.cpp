#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int arr[5][5];
bool check[5][5];

int line = 0;
int num[26];

bool bingo() {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!check[i][j]) {}
			else {
				cnt1++;
				if (cnt1 == 5)answer++;
			}

			if (!check[j][i]) continue;
			else {
				cnt2++;
				if (cnt2 == 5)answer++;
			}
		}
		cnt1 = 0;
		cnt2 = 0;


		if (check[i][i]) {
			cnt3++;
			if (cnt3 == 5)answer++;
		}
		if (check[i][4 - i]) {
			cnt4++;
			if (cnt4 == 5)answer++;
		}
	}
	cnt3 = 0;
	cnt4 = 0;

	if (answer >= 3)return true;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 1; i <= 25; i++) {
		cin >> num[i];

	}



	for (int i = 1; i <= 25; i++) {
		bool check1 = true;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (arr[j][k] == num[i]) {
					check[j][k] = true;
					check1 = false;
					break;
				}

			}
			if (!check1) break;
		}

		if (i >= 12) {
			if (bingo()) {
				cout <<  i << endl;
				break;
			}
		}
	}
	return 0;
}