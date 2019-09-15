#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;

int dp[100001][3];
int n;

int solve(int num, int state) {
	if (num == n)
		return 1;

	int &ret = dp[num][state];

	if (ret != -1)
		return ret;
	if (state == 0) {
		ret = solve(num + 1, 0) % 9901 + solve(num + 1, 1) % 9901 + solve(num + 1, 2) % 9901;
	}
	else if (state == 1) {
		ret = solve(num + 1, 0) % 9901 + solve(num + 1, 2) % 9901;
	}
	else
		ret = solve(num + 1, 0) % 9901 + solve(num + 1, 1) % 9901;

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << solve(0,0) % 9901 << "\n";


	

	return 0;
}