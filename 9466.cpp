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

// const int MAX = 100000;
// int t, n, want[MAX + 1];
// bool visited[MAX + 1];
// bool isdone[MAX + 1];
// int cnt;

// void dfs(int cur) {
// 	visited[cur] = true;

// 	int next = want[cur];
// 	if (!visited[next])dfs(next);
// 	else {
// 		if (!isdone[next]) {
// 			for (int i = next; i != cur; i = want[i]) {
// 				cnt++;// 팀원세고
// 			}
// 			cnt++;//자기자신세고
// 		}
// 	}
// 	isdone[cur] = true;
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> t;
// 	for (int i = 0; i < t; i++) {
// 		memset(visited, false, sizeof(visited));
// 		memset(isdone, false, sizeof(isdone));
// 		cnt = 0;
// 		cin >> n;
// 		for (int i = 1; i <= n; i++) {
// 			cin >> want[i];
// 		}

// 		for (int i = 1; i <= n; i++) {
// 			if (!visited[i]) {
// 				dfs(i);
// 			}
// 		}
// 		cout << n - cnt << "\n";
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int t;
const int MAX = 100000;
int want[MAX + 1];
bool visited[MAX + 1];
bool done[MAX + 1];
int Count = 0;
void dfs(int cur)
{
	int next = want[cur];
	visited[cur] = true;
	if (!visited[next])
		dfs(next);
	else
	{
		if (!done[next])
		{
			for (int i = next; i != cur; i = want[i])
			{
				Count++;
			}
			Count++;
		}
	}
	done[cur] = true;
}
void Solve()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> want[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				dfs(i);
		}
		cout << n - Count << endl;
		fill(visited + 1, visited + n + 1, false);
		fill(done + 1, done + n + 1, false);
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
