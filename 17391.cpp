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
#include <map>
#include <deque>
using namespace std;

int cart[300][300];
int dp[300][300];
int n, m;

bool inside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	else return false;
}

int solve(int y, int x) {
	if (y == n - 1 && x == m - 1) {
		return 1;
	}
	int& ret = dp[y][x];
	if (ret != -1)return ret;
	ret = 987654321;

	int booster = cart[y][x];

	for (int i = 1; i <=booster; i++) {
		if (inside(y + i, x)) {
			ret = min(ret, solve(y+i, x) + 1);
		}
	}
	for (int i = 1; i <= booster; i++) {
		if (inside(y, x + 1)) {
			ret = min(ret, solve(y, x + i) + 1);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cart[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0)-1 << "\n";


	return 0;
}