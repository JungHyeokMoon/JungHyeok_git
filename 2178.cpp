// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// using namespace std;

// int n, m;
// int arr[101][101];
// bool visited[101][101];
// int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

// bool isinside(int x,int y){
// 	return (x >= 0 && x <n) && (y < m &&y >=0);
// }
// int  ret;
// void bfs(int x, int y,int cnt) {

// 	queue<pair<pair<int, int>, int>> q;
// 	visited[x][y] = true;
// 	q.push(make_pair(make_pair(x, y), cnt));
// 	while (!q.empty()) {
// 		int x = q.front().first.first;
// 		int y = q.front().first.second;
// 		int cnt = q.front().second;
// 		q.pop();

// 		if (x == n - 1 && y == m - 1) {
// 			ret = max(ret, cnt);
// 		} //탈출조건
// 		for (int i = 0; i < 4; i++) {
// 			int next_x = x + dir[i][0];
// 			int next_y = y + dir[i][1];
// 			if (visited[next_x][next_y] == false && isinside(next_x, next_y) == true && arr[next_x][next_y] == 1) {

// 				q.push(make_pair(make_pair(next_x, next_y), cnt + 1));
// 				visited[next_x][next_y] = true;
// 			}
// 		}
// 	}
// }
// int main() {
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			scanf("%1d", &arr[i][j]);
// 		}
// 	}
// 	bfs(0, 0,1);
// 	cout << ret << endl;
// 	return 0;
// }

//거리를 구할떄는 visited를 안써도된다.
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<vector<int>> MAP;
vector<vector<int>> dist;

const pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isinside(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}
void Init()
{
	cin >> n >> m;
	MAP.resize(n, vector<int>(m, 0));
	dist.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			MAP[i][j] = str[j] - '0';
		}
	}
}
int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({y, x});
	dist[y][x] = 0;
	while (!q.empty())
	{
		int hy = q.front().first;
		int hx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = hy + d[i].first;
			int nx = hx + d[i].second;

			if (!isinside(ny, nx))
				continue;
			if (dist[ny][nx] >= 0 || MAP[ny][nx] == 0)
				continue;

			q.push({ny, nx});
			dist[ny][nx] = dist[hy][hx] + 1;
		}
	}
	return dist[n - 1][m - 1] + 1;
}
void Solve()
{
	int Distance = bfs(0, 0);
	cout << Distance << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();
	Solve();
	return 0;
}
