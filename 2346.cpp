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

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	deque<pair<int, int>> dq;

	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		dq.push_back(make_pair(i, num));
	}
	while (!dq.empty()) {
		
		cout << dq.front().first << " ";
		int temp = dq.front().second;
		dq.pop_front();
		if (dq.size() == 0)break;
		if (temp > 0) {
			for (int i = 0; i < temp - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < abs(temp); i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	
	return 0;
}