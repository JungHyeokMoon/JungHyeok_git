#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;
int n, d, w;
bool visited[MAX];
priority_queue < pair<int, int> ,vector<pair<int, int>>> pq;
int ret = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		pq.push(make_pair(w, d));
	}
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int date = pq.top().second;
		pq.pop();
		for (int j = date; j > 0; j--) {
			if (!visited[j]) {
				visited[j] = true;
				ret += cost;
				break;
			}
		}
	}

	
	cout << ret << endl;
	
	return 0;
}
