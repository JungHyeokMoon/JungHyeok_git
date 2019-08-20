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

int t, n;
const int MAX = 100000;
int stk[2][MAX];
int dp[MAX][3];

int solve(int c, int status) {
	if (c == n)return 0;
	int &ret = dp[c][status];

	if (ret != -1)return ret;
	
	//status가 0일경우는 왼쪽에 아무것도 붙어있지않음, 1일경우 왼쪽위에 붙어있음, 2일경우 왼쪽아래에붙어있다.
	int result = solve(c + 1, 0);
	if (status != 1)result = max(result, solve(c + 1, 1) + stk[0][c]);
	if (status != 2)result = max(result, solve(c + 1, 2) + stk[1][c]);
	return ret = result;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> stk[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(0, 0) << "\n";
	}
	return 0;
}