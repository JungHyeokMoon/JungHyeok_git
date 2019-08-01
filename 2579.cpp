#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;


int n;
int dp[301];
int stair[301];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> n;
	

	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}
	cout << dp[n] << endl;
	return 0;
}