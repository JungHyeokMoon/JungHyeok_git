#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int t;
int n, k;
int arr[15][15];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 14; i++) {
		arr[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			for (int k = 1; k <= j; k++) {
				arr[i][j] += arr[i-1][k];
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		cout << arr[n][k] << endl;
	}

	return 0;
}
