// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// using namespace std;
// int t, m, n, k, x, y;
// const int MAX = 50;
// int arr[MAX + 1][MAX + 1];
// bool visited[MAX + 1][MAX + 1];
// int ret = 0;
// int dy[4] = { 1,-1,0,0 };
// int dx[4] = { 0,0,1,-1 };

// void dfs(int y, int x) {

// 	for (int i = 0; i < 4; i++) {
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];
// 		if (!arr[ny][nx])continue;
// 		if (visited[ny][nx])continue;
// 		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
// 		visited[ny][nx] = true;
// 		dfs(ny, nx);
// 	}

// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> t;
// 	for (int i = 0; i < t; i++) {
// 		memset(arr, 0, sizeof(arr));
// 		memset(visited, false, sizeof(visited));
// 		ret = 0;
// 		cin >> m >> n >> k;
// 		for (int j = 0; j < k; j++) {
// 			cin >> x >> y;
// 			arr[y][x] = 1;
// 		}
// 		for (int q = 0; q < n; q++) {
// 			for (int w = 0; w < m; w++) {
// 				if (arr[q][w]) {
// 					if (!visited[q][w]) {
// 						dfs(q, w);
// 						visited[q][w] = true;
// 						ret++;
// 					}

// 				}
// 			}
// 		}
// 		cout << ret << "\n";
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int m, n, k;
vector<vector<int>> MAP;
vector<vector<bool>> visited;
const pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isinside(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}
void bfs(int y, int x)
{
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({y, x});
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
			if (MAP[ny][nx] == 0 || visited[ny][nx] == true)
				continue;
			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}
}
int calCase()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (MAP[i][j] == 1 && !visited[i][j])
			{
				ret++;
				bfs(i, j);
			}
		}
	}
	return ret;
}
void Output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Solve()
{
	int t;
	cin >> t;
	while (t--)
	{
		MAP.clear();
		visited.clear();
		cin >> m >> n >> k;
		MAP.resize(n, vector<int>(m, 0));
		visited.resize(n, vector<bool>(m, false));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			MAP[y][x] = 1;
		}

		cout << calCase() << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}