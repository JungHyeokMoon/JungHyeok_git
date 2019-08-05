#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int c;
int n;
vector<int> v;
int solve(int left, int right) {
	if (left == right)
		return v[left]; //기저사례
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve( mid + 1, right));
	int l = mid, r = mid+1;
	int height = min(v[l], v[r]);
	ret = max(ret, height * 2); // 너비가 2인 사각형
	while (left < l || r < right) {
		if (r < right && (l == left || v[l - 1] < v[r + 1])) {
			r++;
			height = min(height, v[r]);
		}
		else {
			l--;
			height = min(height, v[l]);
		}
		ret = max(ret, height*(r - l + 1));
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		
		cout << solve(0, n-1) << endl;

	}
	
	return 0;

}