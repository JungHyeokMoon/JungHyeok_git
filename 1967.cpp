#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int MAX = 10000 + 1;
int n;
int a, b, c;
vector<pair<int, int>> adj[MAX];
bool visited[MAX];
int ret = 0;
int t = 0;
void dfs(int here, int dist) {
	if (visited[here])
		return;

	visited[here] = true;
	if (ret < dist) {
		ret = dist;
		t = here;
	}
	for (unsigned int i = 0; i < adj[here].size(); i++) {
		dfs(adj[here][i].second, dist + adj[here][i].first);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	} //간선 가중치입력
	dfs(1, 0);

	memset(visited, false , sizeof(visited));
	dfs(t, 0);
	cout << ret << endl;

	return 0;
}
