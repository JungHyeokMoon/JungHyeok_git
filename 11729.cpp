#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n;

vector<pair<int, int>>v;

void hanoi(int start, int by, int end, int num) {
	if (num == 1) {
		
		//cout << start << " " << end << endl;
		v.push_back(make_pair(start, end));
	}
	else {
		hanoi(start, end, by, num - 1);
		
		//cout << start << " " << end << endl;
		v.push_back(make_pair(start, end));
		hanoi(by, start, end, num - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	hanoi(1,2,3,n);
	int cnt = v.size();
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	

	return 0;
}
