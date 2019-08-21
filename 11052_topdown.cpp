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
const int MAX = 1000;
int n;
int input[MAX + 1];
int dp[MAX + 1];

int solve(int sum) {
	if (sum > n)
		return -987654321;

	int &ret = dp[sum];
	if (ret != -1)return ret;

	for (int i = 1; i <= n; i++) {
		ret = max(ret, solve(sum + i) + input[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	cout << solve(0)+1<< "\n";
}