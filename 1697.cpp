// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// #include <stack>
// using namespace std;

// const int MAX = 100000;
// int n, k;
// bool visited[MAX + 1];

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n >> k;
// 	queue<pair<int, int>> q;

// 	visited[n] = true;
// 	int ret = 0;
// 	q.push(make_pair(n, ret));// n은좌표 0은카운트

// 	while (!q.empty()) {
// 		int cur = q.front().first;
// 		int cost = q.front().second;
// 		q.pop();

// 		if (cur == k) {
// 			ret = cost;
// 			break;
// 		}

// 		int before = cur - 1;
// 		int next = cur + 1;
// 		int multi = cur * 2;

// 		if (before >= 0 && !visited[before]) {
// 			visited[before] = true;
// 			q.push(make_pair(before, cost + 1));
// 		}
// 		if (next <= MAX && !visited[next]) {
// 			visited[next] = true;
// 			q.push(make_pair(next, cost + 1));
// 		}
// 		if (multi <= MAX && !visited[multi]) {
// 			visited[multi] = true;
// 			q.push(make_pair(multi, cost + 1));
// 		}
// 	}

// 	cout << ret << "\n";

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, k;
vector<int> dist;
const int SIZE = 100000;
queue<int> q;
void Init()
{
	cin >> n >> k;
	dist.resize(SIZE + 1, -1);
}
bool isinside(int h)
{
	if (h >= 0 && h <= SIZE)
		return true;
	return false;
}
void Search(int h, int nh)
{
	if (isinside(nh))
	{
		if (dist[nh] == -1)
		{
			q.push(nh);
			dist[nh] = dist[h] + 1;
		}
	}
}
int transform(int i, int h)
{
	if (i == 0)
		return h - 1;
	else if (i == 1)
		return h + 1;
	else
		return 2 * h;
}
void Solve()
{
	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		int h = q.front();
		// cout << "h : " << h << endl;
		q.pop();

		if (h == k)
		{
			cout << dist[h] << endl;
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			int nh = transform(i, h);
			// cout << "nh : " << nh << endl;
			Search(h, nh);
		}
	}
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