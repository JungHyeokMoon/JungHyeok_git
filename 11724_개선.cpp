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

const int MAX = 1000;
vector<int > adjlist[MAX + 1];
int n, m;
bool visited[MAX + 1];
int ret = 0;

void dfs(int src) {


	for (int i = 0; i < adjlist[src].size(); i++) {
		int next = adjlist[src][i];
		if (visited[next])continue;
		visited[next] = true;
		dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		adjlist[from].push_back(to);
		adjlist[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			visited[i] = true;
			ret++;
		}
	}

	cout << ret << "\n";

	return 0;
}