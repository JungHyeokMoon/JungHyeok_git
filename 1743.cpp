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

const int MAX = 100;
int arr[MAX + 1][MAX + 1];
int n, m, k; //n세로길이,m 가로길이
int r, c;
bool visited[MAX + 1][MAX + 1];

int ret = 0;
int cnt = 0;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs(int y, int x) {

	
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (!arr[ny][nx])continue;
		if (visited[ny][nx])continue;
		if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
		visited[ny][nx] = true;
		cnt++;
		dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		arr[r-1][c-1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j]) {
				cnt = 0;
				//visited[i][j] = true;
				dfs(i, j);
				ret = max(ret, cnt);
			}
		}
	}

	cout << ret << "\n";
	
	return 0;
}