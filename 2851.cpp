#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;
int arr[10];
int sum[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp1 = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		temp1 += arr[i];
		sum[i] = temp1;
	}

	vector<pair<int, int>> v;
	for (int i = 0; i < 10; i++) {
		int temp = 100 - sum[i];
		v.push_back(make_pair(abs(temp), i));
	}

	sort(v.begin(), v.end());

	if (v[0].first == v[1].first) {
		int idx1 = v[0].second;
		int idx2 = v[1].second;
		int ret = max(sum[idx1], sum[idx2]);
		cout << ret << "\n";
	}
	else {
		int idx = v[0].second;
		cout << sum[idx] << "\n";
	}
	return 0;
}