#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
string str1;
string str2;
int dp[1001][1001];
int len1;
int len2;
int solve(int pos1, int pos2) {
	if (pos1 == len1 || pos2 == len2)
		return 0;

	if (str1[pos1] == str2[pos2]) {
		return 1 + solve(pos1 + 1, pos2 + 1);
	}
	int &ret = dp[pos1][pos2];

	if (ret != -1) return ret;
	ret = max(solve(pos1 + 1, pos2), solve(pos1, pos2 + 1));

	return ret = dp[pos1][pos2];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> str1 >> str2;
	len1 = str1.size();
	len2 = str2.size();
	memset(dp, -1,sizeof(dp));
	cout << solve(0, 0) << endl;

	
	return 0;

}