#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
//priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<int>>pq;
int v,e;
const int MAX_V = 10001;
vector<pair<int, int>> adjlist[MAX_V];
long long ret = 0;
priority_queue <pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[MAX_V];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> v >> e; 
	int from, go, weight;
	for (int i = 0; i < e; i++) {
		cin >> from >> go >> weight;
		adjlist[from].push_back(make_pair(weight,go));
		adjlist[go].push_back(make_pair(weight,from));
	}
	
	pq.push(make_pair(0, 1)); //가중치 0과 시작정점 1넣었음

	while (!pq.empty()) {
		int herev = pq.top().second;
		int herec = pq.top().first;

		pq.pop();
		if(visited[herev]==true)continue;

		visited[herev] = true;
		ret += herec;
		

		for (int i = 0; i < adjlist[herev].size(); i++) {
			int nextcost = adjlist[herev][i].first;
			int nextvertex = adjlist[herev][i].second;
			/*if (visited[nextvertex]==true) {
				continue;
			}*/
			pq.push(make_pair(nextcost, nextvertex));
		}
	}
	cout << ret << endl;
}
