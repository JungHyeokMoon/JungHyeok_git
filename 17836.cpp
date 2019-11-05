#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;
int n, m, t;

int queen[101][101];


int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
bool visited[101][101];
int ret = 987654321;

void bfs(int hy, int hx, int ht) {
	bool visited2[101][101] = { false };
	queue<pair<pair<int, int>, int>>q2;
	q2.push(make_pair(make_pair(hy, hx), ht));

	visited2[hy][hx] = true;
	while (!q2.empty()) {
		int hy = q2.front().first.first;
		int hx = q2.front().first.second;
		int ht = q2.front().second;

		q2.pop();

		if (hy == n && hx == m) {
			ret = min(ret, ht);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			int nt = ht + 1;
			if (nt > t)continue;
			if (ny < 0 || ny > n || nx < 0 || nx > m)continue;

			if (visited2[ny][nx])continue;
			visited2[ny][nx] = true;
			q2.push(make_pair(make_pair(ny, nx), nt));
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &queen[i][j]);
		}
	}
	n = n - 1;
	m = m - 1;



	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));

	visited[0][0] = true;

	while (!q.empty()) {
		int hy = q.front().first.first;
		int hx = q.front().first.second;
		int ht = q.front().second;
		q.pop();
		if (hy == n && hx == m) {
			ret = min(ret, ht);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			int nt = ht + 1;
			if (nt > t)continue;
			if (ny < 0 || ny > n || nx < 0 || nx > m)continue;
			if (visited[ny][nx])continue;
			else {
				if (queen[ny][nx] == 0) {
					visited[ny][nx] = true;
					q.push(make_pair(make_pair(ny, nx), nt));
				}
				else if (queen[ny][nx] == 2) {
					bfs(ny, nx, nt);
				}
			}
		}
	}

	if (ret == 987654321) {
		printf("Fail\n");
	}
	else {
		printf("%d\n", ret);
	}
}