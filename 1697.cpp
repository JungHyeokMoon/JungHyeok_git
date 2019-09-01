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
int n, k;
bool visited[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	queue<pair<int, int>> q;


	visited[n] = true;
	int ret = 0;
	q.push(make_pair(n, ret));// n은좌표 0은카운트

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == k) {
			ret = cost;
			break;
		}

		int before = cur - 1;
		int next = cur + 1;
		int multi = cur * 2;
		

		if (before >= 0 && !visited[before]) {
			visited[before] = true;
			q.push(make_pair(before, cost + 1));
		}
		if (next <= MAX && !visited[next]) {
			visited[next] = true;
			q.push(make_pair(next, cost + 1));
		}
		if (multi <= MAX && !visited[multi]) {
			visited[multi] = true;
			q.push(make_pair(multi, cost + 1));
		}
	}

	cout << ret << "\n";


	return 0;
}