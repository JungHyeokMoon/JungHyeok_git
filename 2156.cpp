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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> n;
	
	vector<int> dp(n + 1, 0);
	vector<int> podo(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> podo[i];
	}
	
	dp[1] = podo[1];
	if(n>1)
	dp[2] = podo[2]+podo[1];
	if (n>2){
		for (int i = 3; i <= n; i++) {
			dp[i] = max(max(dp[i - 3] + podo[i] + podo[i - 1], dp[i - 2] + podo[i]), dp[i - 1]);

		}
	}

	cout << dp[n] << endl;
	return 0;

}