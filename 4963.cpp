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

const int MAX = 50;
int w, h;
int island[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int ret = 0;
int dy[8] = { -1,-1,-1,0,0,1,1,1};
int dx[8] = { -1,0,1,-1,1,-1,0,1 };


void dfs(int y, int x) {

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
		if (!island[ny][nx])continue;
		if (visited[ny][nx])continue;
		visited[ny][nx] = true;
		dfs(ny, nx);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		ret = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j]) {
					if (!visited[i][j]) {
						visited[i][j] = true;
						ret++;
						dfs(i, j);
					}
				}
			}
		}
		cout << ret << "\n";

	}
	return 0;

}