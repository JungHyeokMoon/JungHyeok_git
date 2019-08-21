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
int t, m, n, k, x, y;
const int MAX = 50;
int arr[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int ret = 0;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void dfs(int y, int x) {
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!arr[ny][nx])continue;
		if (visited[ny][nx])continue;
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		visited[ny][nx] = true;
		dfs(ny, nx);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		ret = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int q = 0; q < n; q++) {
			for (int w = 0; w < m; w++) {
				if (arr[q][w]) {
					if (!visited[q][w]) { 
						dfs(q, w);
						visited[q][w] = true;
						ret++;
					}
					
				}
			}
		}
		cout << ret << "\n";
	}

	return 0;
}