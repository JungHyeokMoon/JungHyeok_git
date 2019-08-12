#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

const int MAX = 16;
int n;
vector<pair<int, int>> v; //Ti, Pi

int dp[16];

int solve(int date) {
	if (date == n + 1)
		return 0;
	if (date > n + 1) return -987654321; //이거해줘야지 재귀조건에서 n+1넘어갈때 맥스를 체크해줄수있다

	int &ret = dp[date];
	if (ret != -1) return ret;

	
	return ret = max(solve(date+1), solve(date + v[date].first) + v[date].second);

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	

	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}


	memset(dp, -1, sizeof(dp));

	cout << solve(1) << endl;

	return 0;
}