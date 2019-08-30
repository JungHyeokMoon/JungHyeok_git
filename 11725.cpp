#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
using namespace std;

const int MAX = 100000;
vector<int> tree[MAX + 1];
queue<int> q;

int n;
int parent[MAX + 1];
bool visited[MAX + 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);

	}
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int s = tree[cur].size();
		for (int i = 0; i < s; i++) {
			int next = tree[cur][i];
			if (visited[next])continue;
			parent[next] = cur;
			visited[next] = true;
			q.push(next);
		}
	}


	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}