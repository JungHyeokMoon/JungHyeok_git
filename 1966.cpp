#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
using namespace std;
int testcase, n, m;

int importance;
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> testcase;
	
	for (int i = 0; i < testcase; i++) {
		cin >> n >> m;
		queue < pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < n; j++) {
			cin >> importance;
			q.push(make_pair(j, importance));
			pq.push(importance);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int cost = q.front().second;
			q.pop();

			if (pq.top() == cost) {
				cnt++;
				pq.pop();
				if (idx == m) {
					cout << cnt++ << endl;
					break;
				}

			}
			else {
				q.push(make_pair(idx, cost));
			}
		}
		cnt = 0;
		
	}

	
	
	
	return 0;
	
}
