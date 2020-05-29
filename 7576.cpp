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

// const int MAX = 1000;
// int tomato[MAX + 1][MAX + 1];
// int m, n;

// int dx[4] = { 0,0,-1,1 };
// int dy[4] = { -1,1,0,0 };

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	queue <pair<int,int>> q;
// 	cin >> m >>n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> tomato[i][j];
// 			if (tomato[i][j] == 1) {
// 				q.push(make_pair(i, j));
// 			}
// 		}
// 	}

// 	while (!q.empty()) {
// 		int hy = q.front().first;
// 		int hx = q.front().second;
// 		q.pop();
// 		for (int i = 0; i < 4; i++) {
// 			int nx = hx+dx[i];
// 			int ny = hy + dy[i];
// 			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
// 			if (!tomato[ny][nx]) {
// 				tomato[ny][nx] = tomato[hy][hx] + 1;
// 				q.push(make_pair(ny, nx));
// 			}
// 		}
// 	}

// 	int ret = -987654321;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (tomato[i][j] == 0){
// 				cout << -1 << "\n";
// 				return 0;
// 			}
// 			ret = max(ret, tomato[i][j]);
// 		}
// 	}

// 	cout << ret - 1 << "\n";

// 	return 0;

// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<vector<int>> MAP;
vector<vector<int>> dist;
int n, m;
queue<pair<int, int>> q;
const pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isinside(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}
void Init()
{
	cin >> m >> n;
	MAP.resize(n, vector<int>(m, 0));
	dist.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
				q.push({i, j});
			//익은 토마토는 큐에집어넣어서 돌려야함
			else if (MAP[i][j] == 0)
				dist[i][j] = -1; //덜익은 토마토는 거리 -1에서시작
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << MAP[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
}
void Check()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1 << endl; //bfs돌렸는데 다익지않는게나올경우
				return;
			}
			ret = max(ret, dist[i][j]); // 익은것들중 거리제일큰것
		}
	}
	cout << ret << endl;
}
void bfs()
{
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
			if (dist[ny][nx] >= 0 || MAP[ny][nx] == -1)
				continue;

			q.push({ny, nx});
			dist[ny][nx] = dist[hy][hx] + 1;
		}
	}
}
void Solve()
{
	bfs();
	Check();
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