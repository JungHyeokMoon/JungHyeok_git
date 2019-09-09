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

const int MAX=500;
int t;
int n;
int dp[MAX + 1][MAX + 1];
int file[MAX + 1];
int psum[MAX + 1];

int solve(int i, int j) {
	if (i == j) {
		return 0;
	}
	if (i + 1 == j)
		return file[i] + file[j];

	int &ret = dp[i][j];
	if (ret != 0x3f3f3f3f) {
		return ret;
	}
	for (int k = i; k < j; k++) {
		int left = solve(i, k);
		int right = solve(k + 1, j);
		ret = min(ret, left + right);
	}
	return ret += psum[j] - psum[i - 1];


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> file[i];
			psum[i] = psum[i - 1] + file[i];
		}
		memset(dp, 0x3f, sizeof(dp));
		cout << solve(1, n) << "\n";
	}
	return 0;
}