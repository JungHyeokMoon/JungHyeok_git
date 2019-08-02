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
const int MAX = 68;
long long dp[MAX];
long long koong(int n) {

	long long &ret = dp[n];
	if (ret != -1) return ret;

	return ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> t;
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int num;
	for (int i = 0; i < t; i++) {
		cin >> num;
		cout << koong(num) << endl;
	}
	
	return 0;

}