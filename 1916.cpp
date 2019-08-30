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
const int MAX = 1000;
vector<pair<int, int>> adjlist[MAX + 1];
priority_queue<pair<int, int>> pq; //cost vertex
int dist[MAX + 1];
int start, destination;
const int INF = 987654321;
int  dijkstra(int s,int d) {
	vector<int> dist(n + 1, INF);
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		
		if (cur == d)
			return cost;

		if (dist[cur] < cost)
			continue;

		int s = adjlist[cur].size();
		for (int i = 0; i < s; i++) {
			int there = adjlist[cur][i].first;
			int nextcost = adjlist[cur][i].second + cost;
			if (dist[there] > nextcost) {
				dist[there] = nextcost;
				pq.push(make_pair(-nextcost, there));
			}
		}
	}
}
/*vector<int> dijkstra(int s) {
	vector<int> dist(n + 1, INF);
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();


		if (dist[cur] < cost)
			continue;

		int s = adjlist[cur].size();
		for (int i = 0; i < s; i++) {
			int there = adjlist[cur][i].first;
			int nextcost = adjlist[cur][i].second + cost;
			if (dist[there] > nextcost) {
				dist[there] = nextcost;
				pq.push(make_pair(-nextcost, there));
			}
		}
	}
	return dist;
}*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int from, to, weight;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		adjlist[from].push_back(make_pair(to, weight));
	}

	cin >> start >> destination;

	//vector<int> answer = dijkstra(start);


	//cout << answer[destination] << "\n";
	cout << dijkstra(start, destination) << "\n";
	
	return 0;
}