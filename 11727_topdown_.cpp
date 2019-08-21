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

long long dp[MAX + 1];
int n;
long long solve(int N) {
	if (N == 0) return 0;

	long long &ret = dp[N];
	if (ret != -1)return ret;

	return ret= solve(N - 1)%10007 + 2*solve(N - 2)%10007;

	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;


	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	
	cout << solve(n)%10007 << endl;
}