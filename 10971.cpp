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

int W[10][10];
int n;

bool visited[10];
int ret = 987654321;
int startnode = 0;


void dfs(int Node, int cnt,int len) {
	if (cnt == n - 1) {
		if (W[Node][startnode]) {
			ret = min(ret, len + W[Node][startnode]);
			return;
		}
	}

	for (int next = 0; next < n; next++) {
		if (!visited[next] && W[Node][next]) {
			visited[next] = true;
			dfs(next, cnt + 1, len + W[Node][next]);
			visited[next] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		startnode = i;
		visited[startnode] = true;
		dfs(i, 0, 0);
	}

	cout << ret << "\n";

	
	return 0;
}