#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

const int MAX = 100;
int student[MAX];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		student[i] = i + 1;
		cin >> num;
		for (int j = i; j>i-num; j--) {
			int temp = student[j];
			student[j ] = student[j-1];
			student[j-1] = temp;

		}
	}
	for (int i = 0; i < n; i++) {
		cout << student[i] << " ";
	}

	return 0;
}