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
	int n, s, m;

	int volume[101];
	const int MAX = 100;
	const int MAXV = 1000;
	int dp[MAX+1][MAXV+1];

	int solve(int idx,int v) {
		if (v<0 || v>m)
			return -987654321;
	
		if (idx == n)
			return v;

		int &ret = dp[idx][v];
		if (ret != -1)
			return ret;

		ret = max(solve(idx + 1, v + volume[idx]), solve(idx + 1, v - volume[idx]));
		return ret;

	
	}

	int main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n >> s >> m;
	
		for (int i = 0; i < n; i++)
			cin >> volume[i];

		memset(dp, -1, sizeof(dp));
		int ans = solve(0, s);
		if (ans == -987654321)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	
	
		return 0;
	}