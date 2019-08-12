#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

const int MAX = 501;
int c;
int n;
vector<int> A;



int dp[MAX];
int solve(int start) {
	int &ret = dp[start+1];
	if (ret != -1)return ret;

	ret = 1; // 최소 길이는 1이기때문에

	for (int i = start+1; i < n; i++) {
		if (start == -1 || A[start] < A[i])
			ret = max(ret, solve(i) + 1);
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
		A.resize(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];

		memset(dp, -1, sizeof(dp));
		cout << solve(-1)-1 << endl;
	}

	return 0;
}