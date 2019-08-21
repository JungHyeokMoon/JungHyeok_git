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
const int MAX = 90;
int n;
long long dp[MAX + 1];

long long solve(int N) {
	if (N == 0) return 0;

	long long &ret = dp[N];
	if (ret != -1)return ret;

	return ret= solve(N - 1) + solve(N - 2);

	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 1;


	cout << solve(n) << "\n";
	return 0;
}