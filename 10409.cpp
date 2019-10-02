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

int n, t;
const int MAX = 50;
int time[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> t;
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> time[i];
		sum += time[i];
		if (sum > t) {
			cout << i << "\n";
			flag = true;
			break;
		}
	}
	if (!flag)cout << n << "\n";
	return 0;
}	

