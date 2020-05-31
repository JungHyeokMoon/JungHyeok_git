// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// using namespace std;
// const int MAX = 300;

// bool isinside(int x, int y,int l) {
// 	return (x >= 0 && x < l) && (y >= 0 && y < l);
// }
// int t;
// int l;
// int hx, hy;
// int dx, dy;

// struct x_y {
// 	int x, y;
// };
// x_y arr[8] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> t;
// 	for (int i = 0; i < t; i++) {
// 		cin >> l >> hx >> hy >> dx >> dy;
// 		queue<pair<int, pair<int, int>>> q;
// 		bool visited[300][300] = { false };
// 		q.push(make_pair(0, make_pair(hx, hy)));
// 		visited[hx][hy] = true;
// 		while (!q.empty()) {
// 			int cnt = q.front().first;
// 			int hx = q.front().second.first;
// 			int hy = q.front().second.second;
// 			q.pop();
// 			if (hx == dx && hy == dy) {
// 				cout << cnt << endl;
// 				break;
// 			}
// 			for (int i = 0; i < 8; i++) {
// 				int nx = hx + arr[i].x;
// 				int ny = hy + arr[i].y;
// 				if (isinside(nx, ny, l) && visited[nx][ny]==false) {
// 					visited[nx][ny] = true;
// 					q.push(make_pair(cnt + 1, make_pair(nx, ny)));
// 				}

// 			}
// 		}
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int t, l;
vector<vector<int>> Dist;
const pair<int, int> d[8] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
bool isinside(int y, int x)
{
	if (y >= 0 && y < l && x >= 0 && x < l)
		return true;
	return false;
}
int bfs(int sy, int sx, int dy, int dx)
{
	queue<pair<int, int>> q;
	q.push({sy, sx});
	Dist[sy][sx] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		int hy = cur.first;
		int hx = cur.second;
		q.pop();
		if (hy == dy && hx == dx)
		{
			return Dist[dy][dx];
		}
		for (int i = 0; i < 8; i++)
		{
			int ny = hy + d[i].first;
			int nx = hx + d[i].second;
			if (!isinside(ny, nx))
				continue;
			if (Dist[ny][nx] >= 0)
				continue;
			Dist[ny][nx] = Dist[hy][hx] + 1;
			q.push({ny, nx});
		}
	}
}
void Solve()
{
	cin >> t;
	while (t--)
	{
		cin >> l;
		Dist.resize(l, vector<int>(l, -1));
		int sy, sx, dy, dx;
		cin >> sy >> sx >> dy >> dx;
		cout << bfs(sy, sx, dy, dx) << endl;
		Dist.clear();
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
