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
int dp[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;

	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = 100001;

	/* for (int i = 1; i <= n; i++)
		dp[i] = i;
*/
	for (int i = 2; i <= n; i++)
		for (int j = 1; j*j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[n] << endl;

	return 0;

}