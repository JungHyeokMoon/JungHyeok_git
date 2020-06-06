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

// const int MAX = 1000000;
// bool visited[MAX + 1];
// int f, s, g, u, d;

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> f >> s >> g >> u >> d; //총 f층, 가려는곳 g층, 현재 있는층 s층,u버튼은 위로 u층 ,d버튼은 아래로 d층

// 	queue<pair<int, int>> q;
// 	q.push(make_pair(s, 0));
// 	int ret = 0;
// 	visited[s] = true;
// 	bool flag = false;

// 	if (s == g) {
// 		cout << 0 << "\n";
// 		return 0;
// 	}
// 	while (!q.empty()) {
// 		int here = q.front().first;
// 		int cnt = q.front().second;
// 		q.pop();

// 		int uf = here + u;
// 		int df = here - d;
// 		if (uf == g||df==g) {
// 			ret = cnt + 1;
// 			flag = true;
// 			break;
// 		}

// 		if (1 <= uf && uf <= f) {
// 			if (!visited[uf]) {
// 				q.push(make_pair(uf, cnt + 1));
// 				visited[uf] = true;
// 			}
// 		}

// 		if (1 <= df && df <= f) {
// 			if (!visited[df]) {
// 				q.push(make_pair(df, cnt + 1));
// 				visited[df] = true;
// 			}
// 		}

// 	}
// 	if (flag) {
// 		cout << ret << "\n";
// 	}
// 	else {
// 		cout << "use the stairs" << "\n";
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int f, s, g, u, d;
vector<int> Dist;
void Input()
{
	cin >> f >> s >> g >> u >> d;
	Dist.resize(f + 1, -1);
}
bool IsInside(int c)
{
	if (c >= 1 && c <= f)
		return true;
	return false;
}
int nextFloor(int h, int idx)
{
	return idx == 0 ? h - d : h + u;
}

void Solve()
{
	Dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int c = q.front();
		// cout << "c : " << c << "dist : " << Dist[c] << endl;
		q.pop();
		if (c == g)
		{
			cout << Dist[g] << endl;
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int nc = nextFloor(c, i);
			if (!IsInside(nc))
				continue;
			if (Dist[nc] >= 0)
				continue;
			q.push(nc);
			Dist[nc] = Dist[c] + 1;
		}
	}

	cout << "use the stairs" << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solve();
	return 0;
}