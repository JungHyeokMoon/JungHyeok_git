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

const int MAX = 1000; 
vector<pair<int, int>>adjlist[MAX+1]; 
priority_queue<pair<int, int>>pq; //pair는 첫번째원소로 대소를비교합니다 그러므로 cost,vertex
int n, m;
int p, q, r;

int dist[MAX + 1];
int before[MAX + 1];

void print(int r) {
	if (before[r] == 1) {
		cout << 1 << " " << r << " ";
		return;
	}
	else {
		print(before[r]);
		cout << r << " ";
	}
}

void dijkstra()
{

	for (int i = 1; i <= n; i++)
		dist[i] = -987654321;
	dist[1] = 0;
	pq.push(make_pair(0,1));
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur] > cost)
			continue;

		int s = adjlist[cur].size();
		for (int i = 0; i < s; ++i)
		{
			int toNode = adjlist[cur][i].first;
			int toCost = adjlist[cur][i].second;
			if (dist[toNode] < cost + toCost)
			{
				dist[toNode] = cost + toCost;
				before[toNode] = cur;
				if (toNode != 1)
					pq.push({ dist[toNode],toNode });
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> p >> q >> r;
		adjlist[p].push_back(make_pair(q, r));
	}
	dijkstra();
	cout << dist[1] << "\n";
	print(1);
	

	return 0;
}