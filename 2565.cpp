#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int dp[100];

int solve(int start) {
	int& ret = dp[start];
	if (ret != -1)return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (v[start].second < v[next].second) {
			ret = max(ret, solve(next) + 1);
		}
	}

	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	memset(dp, -1, sizeof(dp));


	sort(v.begin(), v.end());
	
	//
	//cout << "\n";
	//for (int i = 0; i < n; i++)
	//	cout << v[i].first << " " << v[i].second << "\n";

	//cout << "\n";
	

	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, solve(i));
	}

	cout << n-ret << "\n";
	//cout << solve(0) << "\n";
	

	
	return 0;
}