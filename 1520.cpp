#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int m, n;
const int MAX = 500;
int arr[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];
//bool isvisited[MAX + 1][MAX + 1];
int dy[4] = {-1,0,1,0};
int dx[4] = { 0,1,0,-1 };
int solve(int hy, int hx) {
	if (hy == m - 1 && hx == n - 1)
		return 1;

	

	int& ret = dp[hy][hx];
	if (ret != -1)return ret;

	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = hy + dy[i];
		int nx = hx + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n)continue;
		
		if (arr[hy][hx] > arr[ny][nx])
		ret+=solve(ny, nx);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	
	cout << solve(0, 0) << "\n";
	
	return 0;
}