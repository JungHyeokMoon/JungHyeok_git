#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 101;
int n, m;
int cnt = 0;
int a, b;
vector<int> adj[MAX];
bool visited[MAX] = { false };
void dfs(int here) {
	visited[here] = true;
	
	
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (visited[next] == false) {
			cnt++;
			dfs(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << cnt<< endl;
	
	return 0;
	
}
