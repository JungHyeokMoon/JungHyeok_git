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

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int >dq;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	
	int ret = 0;
	for(int i=0; i<m; i++){
		int num;
		cin >> num;
		int front = 0;
		int back = 0;
		for (auto p = dq.begin(); p != dq.end(); p++) {
			if (*p == num)
				break;
			front++;
		}
		back = dq.size() - front - 1;
		if (front <= back) {
			for (int j = 1; j <= front; j++) {
				dq.push_back(dq.front());
				dq.pop_front();
				ret++;
			}
		}
		else {
			for (int j = 0; j <= back; j++) {
				dq.push_front(dq.back());
				dq.pop_back();
				ret++;
			}
		}
		dq.pop_front();
	}
	
	cout << ret << "\n";


	return 0;
}	