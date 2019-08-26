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

const int MAX = 100;
int n, m;
int cal1, cal2;
int x, y;
vector<int> adjlist[MAX + 1];
bool visited[MAX + 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> cal1 >> cal2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}
	bool flag = false;
	int ret = 0;
	
	queue < pair<int, int>> q;

	q.push(make_pair(cal1, 0));
	visited[cal1] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < adjlist[cur].size(); i++) {
			int next = adjlist[cur][i];
			//cnt = cnt + 1;
			if (next == cal2) {
				flag = true;
				cnt = cnt + 1;
				break;
			}
			if (visited[next])continue;
			visited[next] = true;
			q.push(make_pair(next, cnt+1));

		}
		if (flag) {
			ret = cnt;
			break;

		}
	}

	if (flag) cout << ret << "\n";
	else {
		cout << -1 << "\n";
	}

	return 0;
}