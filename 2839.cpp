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
int n;

int dp[5001];

int sultang(int num) {
	if (num < 0) return 987654321;
	if (num == 0) return 0;

	int &ret = dp[num];
	if (ret != -1)return ret;

	return ret = min(sultang(num-3) , sultang(num-5) )+1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[3] = 1;
	dp[5] = 1;

	int ret = sultang(n);
	if (ret >= 987650000) {
		cout << "-1" << "\n";
	}
	else {
		cout << ret << "\n";
	}

	return 0;
}