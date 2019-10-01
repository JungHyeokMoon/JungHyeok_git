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


int n, k;
const int MAX = 1000;
class olympic {
public:
	int idx;
	int gold;
	int silver;
	int bronze;

};
olympic v[MAX + 1];
bool cmp( olympic& a, olympic& b) {
	if (a.gold > b.gold) {
		return true;
	}
	else if (a.gold == b.gold) {
		if (a.silver > b.silver) {
			return true;
		}
		else if (a.silver == b.silver) {
			if (a.bronze > b.bronze) {
				return true;
			}
			else if (a.bronze == b.bronze) {
				return a.idx == k; // 같은랭크일경우 k번째가 제일 앞에오게끔
			}
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> v[i].idx >> v[i].gold >> v[i].silver >> v[i].bronze;
	}
	sort(v, v + n, cmp);
	
	for (int i = 0; i < n; i++) {
		if (v[i].idx == k) {
			cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}	