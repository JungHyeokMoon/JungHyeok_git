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
#include <iomanip>
#include <math.h>
using namespace std;

int n, m;
const int MAX = 1000000;
int tree[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	sort(tree, tree + n);

	int lo = 0;
	int hi = 1000000000;
	
	while (lo+1<hi) {
		long long sum = 0;
		int mid = (lo + hi) / 2;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		 if (sum >= m) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	cout << lo << "\n";

	
	return 0;
}