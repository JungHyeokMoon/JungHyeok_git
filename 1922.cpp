#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int MAX = 1000 + 1;
int n, m;
int a, b, c;
vector <pair<int,int>> adj[MAX];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int ret = 0;
bool visited[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair( c, b ));
		adj[b].push_back(make_pair( c,a ));
	}

	pq.push(make_pair( 0,1 )); //시작점
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		if (!visited[vertex]) {
			visited[vertex] = true;
			ret += cost;
			for (int i = 0; i < adj[vertex].size(); i++) {
				int nextcost = adj[vertex][i].first;
				int nextvertex = adj[vertex][i].second;

				if (!visited[nextvertex]) {
					pq.push(make_pair(nextcost, nextvertex));
				}
			}
		}
	}
	
	printf("%d\n", ret);
	return 0;
}