#include <iostream>
#include <algorithm>
using namespace std;


int arr[10];
int n;
int ans;
int val;
int func(int l, int r) {
	int ret = 1;
	for (int i = l; i < r+1; i++)
		ret *= arr[i];
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				val = func(1, i) + func(i + 1, j) + func(j + 1, k) + func(k + 1, n);
				ans = max(ans, val);
			}
		}
	}
	cout << ans;

	

}