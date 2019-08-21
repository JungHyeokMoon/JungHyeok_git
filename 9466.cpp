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

const int MAX = 100000;
int t, n, want[MAX + 1];
bool visited[MAX + 1];
bool isdone[MAX + 1];
int cnt;

void dfs(int cur) {
	visited[cur] = true;

	int next = want[cur];
	if (!visited[next])dfs(next);
	else {
		if (!isdone[next]) {
			for (int i = next; i != cur; i = want[i]) {
				cnt++;// 팀원세고
			}
			cnt++;//자기자신세고
		}
	}
	isdone[cur] = true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(visited, false, sizeof(visited));
		memset(isdone, false, sizeof(isdone));
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> want[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - cnt << "\n";
	}

	return 0;
}