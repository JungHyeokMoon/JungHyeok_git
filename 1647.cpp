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

int n, m;
const int MAX = 100000;
vector<pair<int, int>>adjlist[MAX + 1];
int ret = 0;
bool visited[MAX + 1];
void prim(int start) {
	visited[start] = true;
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < adjlist[start].size(); i++) {
		int next = adjlist[start][i].first;
		int cost = -adjlist[start][i].second;
		pq.push(make_pair(cost, next));
	}
	int maxcost = -987654321;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (visited[cur])continue;
		visited[cur] = true;
		ret += cost;
		maxcost = max(maxcost, cost);


		int s = adjlist[cur].size();
		for (int i = 0; i < s; i++) {
			pq.push(make_pair(-adjlist[cur][i].second, adjlist[cur][i].first));
		}
	}

	ret = ret - maxcost;
	return;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjlist[a].push_back(make_pair(b,c));
		adjlist[b].push_back(make_pair(a,c));
	}

	prim(1);
	cout << ret << "\n";

	return 0;
}