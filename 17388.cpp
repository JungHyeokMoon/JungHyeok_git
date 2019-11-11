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

int s, k, h;
int sum = 0;
map<int, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d %d %d", &s, &k, &h);
	sum = s + k + h;
	if (sum >= 100) {
		cout << "OK" << "\n";
	}
	else {
		m.insert(make_pair(s, 0));
		m.insert(make_pair(k,1));
		m.insert(make_pair(h, 2));
		map<int, int >::iterator iter = m.begin();
		if (iter->second == 0) {
			cout << "Soongsil" << "\n";
		}
		else if (iter->second == 1) {
			cout << "Korea" << "\n";
		}
		else {
			cout << "Hanyang" << "\n";
		}
	}


	return 0;
}