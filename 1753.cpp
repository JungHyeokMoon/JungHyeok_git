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
int V, E, K;

const int MAXV = 20001;
const int INF = 987654321;


vector<pair<int, int>> adjlist[MAXV];

vector<int> dijkstra(int start, int vertex) {
	vector<int> dist(vertex, INF);
	dist[start] = 0;// 자기자신으로가는비용 0

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)continue;
		for (int i = 0; i < adjlist[here].size(); i++) {
			int there = adjlist[here][i].first;
			int nextcost = cost+adjlist[here][i].second;
			
			if (dist[there] > nextcost) {
				dist[there] = nextcost;
				pq.push(make_pair(-nextcost, there));
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	V++;
	int u, v, w;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adjlist[u].push_back(make_pair(v, w));
	}
	
	vector<int> ans = dijkstra(K, V);

	for (int i = 1; i < V; i++) {
		if (ans[i] == INF)cout << "INF" << "\n";
		else
			cout << ans[i] << "\n";
	}

	return 0;
}