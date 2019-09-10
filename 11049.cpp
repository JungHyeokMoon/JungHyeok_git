#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;

int n;
int dp[501][501];
int d[501];

int solve(int i, int j) {
	if (i == j) {
		return 0;
	}
	
	/*int &ret = dp[i][j];
	if (ret != 0x3f3f3f3f) {
		return ret;
	}*/
	if (dp[i][j] != 0x3f3f3f3f) {
		return dp[i][j];
	}

	for (int k = i; k < j; k++) {
		int left = solve(i, k);
		int right = solve(k + 1, j);
		dp[i][j] = min(dp[i][j], left+right + d[i - 1] * d[k] * d[j]);
	}
	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i - 1] >> d[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	cout << solve(1, n) << "\n";

	
	return 0;
}