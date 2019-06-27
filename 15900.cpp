#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX= 5000001;

vector<int> adj [MAX];
bool visited[MAX];
int n;
int a, b;
long long ret;

void dfs(int here, int dist) {
	visited[here] = true;
	bool isleaf = true;
	for (int & go : adj[here]) {
		if (visited[go] == true) continue;
		isleaf = false;
		dfs(go, dist + 1);
	}
	if (isleaf == false)return; // 리프노드가 아니면 return 리프노드일때만 높이계산해주기위해서
	ret += dist;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	if (ret % 2 == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;

}