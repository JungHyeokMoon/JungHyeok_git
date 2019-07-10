#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 100000;
int n;

int arr[MAX];

int histogram(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return arr[s];

	int mid = (s + e) / 2;
	int result = max(histogram(s, mid), histogram(mid, e));

	int w = 1, h = arr[mid], r = mid, l = mid;
	while (r - l + 1 < e - s) {
		int p = l > s ? min(h, arr[l - 1]) : -1;
		int q = r < e ? min(h, arr[r + 1]) : -1;

		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		result = max(result, ++w*h);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << histogram(0,n) << endl;
	return 0;
}



