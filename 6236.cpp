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

const int MAX = 100000;
int n, m, k;
int money[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int lo = -987654321;
	int hi = 1e9;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		lo = max(lo, money[i]);
	}
	
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + money[i] >= mid) {
				cnt++;
				sum = 0;
			}
			sum += money[i];
		}
		if (sum != 0)cnt++;

		if (cnt > m)lo = mid;
		else hi = mid;
		
	}
	cout << lo << "\n";
	
	return 0;
}