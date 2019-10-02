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

int x, y, t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		int dist = y - x;
		long long n = 1;
		long long pown = 0;
		long long minn;
		long long maxn;
		long long ret = 0;
		while (1) {
			pown = n * n;
			minn = n * n - n + 1;
			maxn = n * n + n;
			if (minn <= dist && dist <= maxn) {
				if (minn <= dist && dist <= pown) ret = 2 * n - 1;
				else ret = 2 * n;
				break;
			}
			n++;
		}
		cout << ret << "\n";
	}
	return 0;
}	

