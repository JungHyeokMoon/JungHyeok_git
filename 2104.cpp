#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 100001;
int A[MAX];
int n;
long long result;
long long sol(int s, int e) {
	if (s == e) {
		return (long long) A[s] * A[s];
	}
	int mid = (s + e) / 2;
	int l = mid, r = mid;
	long long sum = A[mid];
	result = max(sol(s, mid), sol(mid + 1, e));
	int h = A[mid];
	while (r - l <= e - s) {
		int lh = l > s ? min(h, A[l - 1]) : -1;
		int rh = r < e ? min(h, A[r + 1]) : -1;

		if ((sum + A[l - 1]) * lh >= (sum + A[r + 1]) * rh) {
			sum += A[l - 1];
			h = lh;
			l--;
		}
		else {
			sum += A[r + 1];
			h = rh;
			r++;
		}
		result = max(result, sum*h);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	cout << sol(1, n);
	return 0;
}




