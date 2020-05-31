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

// const int MAX = 25;
// int arr[MAX + 1][MAX + 1];
// bool visited[MAX + 1][MAX + 1];
// int dy[4] = { 1,-1,0,0 };
// int dx[4] = { 0,0,1,-1 };
// int n;
// vector<int> answer;
// int cnt = 0;

// void dfs(int y, int x) {

// 	for (int i = 0; i < 4; i++) {
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];
// 		if (arr[ny][nx]==0)continue;
// 		if (visited[ny][nx])continue;
// 		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
// 		cnt++;
// 		visited[ny][nx] = true;
// 		dfs(ny, nx);
// 	}

// }
// int main() {
// 	//ios::sync_with_stdio(false);
// 	//cin.tie(NULL);
// 	//cout.tie(NULL);

// 	cin >> n;

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			scanf("%1d", &arr[i][j]);
// 		}
// 	}

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (!visited[i][j] && arr[i][j]) {
// 				visited[i][j] = true;
// 				cnt = 1;
// 				dfs(i, j);
// 				answer.push_back(cnt);
// 			}
// 		}
// 	}

// 	sort(answer.begin(), answer.end());
// 	int len = answer.size();
// 	cout << len << "\n";
// 	for (int i = 0; i < len; i++) {
// 		cout << answer[i] << "\n";
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<vector<int>> MAP;
vector<vector<bool>> visited;
int n;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<int> ret;
void Output()
{
	sort(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for (auto i : ret)
	{
		cout << i << " ";
	}
}
void Init()
{
	cin >> n;
	visited.resize(n, vector<bool>(n, false));
	MAP.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			MAP[i][j] = str[j] - '0';
		}
	}
}
bool isinside(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n)
		return true;
	return false;
}
int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({y, x});
	int temp = 0;
	;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int hy = cur.first;
		int hx = cur.second;
		temp++;
		for (int i = 0; i < 4; i++)
		{
			int ny = hy + d[i].first;
			int nx = hx + d[i].second;
			if (!isinside(ny, nx))
				continue;
			if (visited[ny][nx])
				continue;
			if (MAP[ny][nx] == 0)
				continue;
			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}
	return temp;
}
void Cal()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[i][j] == 1 && visited[i][j] == false)
			{
				ret.push_back(bfs(i, j));
			}
		}
	}
}
void Solve()
{
	Cal();
	Output();
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