#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int n, k;

int dp[100001];
int coins[101];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i <= 100000; i++)
		dp[i] = 100001;

	for (int i = 1; i <= n; i++)
		cin >> coins[i];
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]]+1);
		}
	}

	if (dp[k] == 100001)cout << "-1" << endl;
	else cout << dp[k] << endl;
	return 0;

}