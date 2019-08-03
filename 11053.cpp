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
	vector<int> input(n , 0);
	vector<int> dp(n , 1);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int ret = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (input[j] < input[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}

	cout << ret << endl;

	return 0;

}