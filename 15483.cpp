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

string A, B;

int dp[1001][1001];

int solve(int i, int j) {
	if (i < 0 && j < 0)
		return 0;

	int &ret = dp[i][j];
	if (ret != -1)
		return ret;

	if (A[i] == B[j])
		return ret = solve(i - 1, j - 1);
	else {
		return ret = 1 + min(min(solve(i - 1, j - 1), solve(i - 1, j)), solve(i, j - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string temp1, temp2;
	A = " ";
	B = " ";
	cin >> temp1 >> temp2;
	A += temp1;
	B += temp2;
	int len1 = A.size();
	int len2 = B.size();

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= len1-1; i++)
		dp[i][0] = i;
	for (int j = 0; j <= len2-1; j++)
		dp[0][j] = j;

	
	cout << solve(len1-1 , len2-1 ) << "\n";

	return 0;
}
