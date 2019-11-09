#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;

int n, m, k;
const int MAX = 100001;

vector<pair<int,int>> adjlist[MAX];

int interview[MAX];

int ret = -987654321;



/*bool compare(pair<long long ,int >a, pair<long long ,int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}*/

void solve(int vertex) {
	vector<long long> dist(vertex+1,50000000001);
	dist[0] = 0;
	priority_queue<pair<long long, int>> pq; //cost vertex
	for (int i = 0; i < k; i++) {
		pq.push(make_pair(0, interview[i]));
		dist[interview[i]] = 0;
	}
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue; // 원래 저장되어있던값이랑 계산할값이랑 비교해봤을때 계산할값이 더크면의미가없다
		for (unsigned int i = 0; i < adjlist[here].size(); i++) {
			
			int next = adjlist[here][i].first; 
			
			long long nextcost = cost+adjlist[here][i].second;

			if (dist[next] > nextcost) {
				dist[next] = nextcost;
				pq.push(make_pair(-nextcost, next));
			}
		}

	}

	
	vector<pair<long long, int>>ret;
	for (int i = 0; i <=n; i++) {
		ret.push_back(make_pair(dist[i], i));
	}
	sort(ret.begin(), ret.end());

	long long answer1 = ret.back().first;
	int answer2 = ret.back().second;

	for (int i = n - 1; i >= 0; i--) {
		if (answer1 == ret[i].first) {
			answer2 = min(answer2, ret[i].second);
			//cout << answer2 << "\n" << answer1 << "\n";
		}
		else {
			cout << answer2 << "\n" << answer1 << "\n";
			break;
		}
		
	}
	/*int answer2;

	for (int i = 0; i <= n-1; i++) {
		if (i == 0) {
			if (ret[i].first != ret[i + 1].first) {
				cout << ret[i].second << "\n" << ret[i].first << "\n";
				break;
			}
			else {

			}
		}
	}*/


	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adjlist[to].push_back(make_pair(from, cost));
	}


	for (int i = 0; i < k; i++) {
		scanf("%d", &interview[i]);
	}
	solve(n);

	return 0;
}