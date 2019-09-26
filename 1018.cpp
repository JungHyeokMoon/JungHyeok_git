#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;
int n, m;
string chess[50];

int result = 987654321;

int solve1(int y, int x) {
	int cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (chess[i][j] != 'W')
					cnt++;
			}
			else {
				if (chess[i][j] != 'B')
					cnt++;
			}
		}
	}
	return cnt;
}

int solve2(int y, int x) {
	int cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (chess[i][j] != 'B')
					cnt++;
			}
			else {
				if (chess[i][j] != 'W')
					cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> chess[i];
	}

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			result=min(result, min(solve1(i, j), solve2(i, j)));
		}
	}

	cout << result << "\n";


	return 0;
}