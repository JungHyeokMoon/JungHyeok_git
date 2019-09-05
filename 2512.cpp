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

const int MAX = 10000;
int arr[MAX + 1];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	long long sum = 0;
	int h = -987654321;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		h = max(h, arr[i]);
	}
	cin >> m;
	if (sum <= m) {
		cout << h << "\n";
		return 0;
	}

	int lo = 0;
	int hi = h;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid) {
				sum += arr[i];
			}
			else
				sum += mid;
		}

		if (sum <= m) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	cout << lo << "\n";
	
	return 0;
}