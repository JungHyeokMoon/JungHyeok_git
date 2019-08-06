#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int n, m;
int miro[1001][1001];
int dp[1001][1001];

int dir[3][2] = { {-1,0},{0,-1},{-1,-1} };

int solve(int hx, int hy) {
	if (hx < 1 || hy < 1)
		return 0;
	int &ret = dp[hx][hy];
	if (ret != -1) return ret;
	for (int i = 0; i < 3; i++) {
		int px = hx + dir[i][0];
		int py = hy + dir[i][1];

		ret = max(ret, solve(px, py) + miro[hx][hy]);
	}
	
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> miro[i][j];
		}
	}
	dp[1][1] = miro[1][1];
	cout << solve(n, m) << endl;
	return 0;

}