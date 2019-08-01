#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int t;
const int MAX = 101;
long long dp[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	cin >> t;
	int num;
	for (int i = 1; i <= t; i++) {
		cin >> num;
		cout << dp[num] << '\n';
	}
	
	return 0;
}