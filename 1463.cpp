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

const int MAX = 1000000;
int dp[MAX + 1];
int n;


int solve(int num) {
	if (num == 1) return 0;

	int &ret = dp[num];

	if (ret != -1)return ret;

	int result = solve(num - 1) + 1;
	if (num % 3 == 0)result = min(result, solve(num / 3) + 1);
	if (num % 2 == 0) result = min(result, solve(num / 2) + 1);

	return ret = result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	
	cin >> n;

	cout << solve(n) << "\n";
	return 0;
}