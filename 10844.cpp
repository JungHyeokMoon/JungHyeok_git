#include <iostream>
#include <algorithm>
using namespace std;

int dp[100 + 1][100 + 1];//길이가 n이고 마지막숫자가 j인계단의수 (i,j)

int main() {
	int n;
	scanf("%d", &n);
	
	long long mod = 1000000000;

	for (int i = 1; i <= 9; i++) dp[1][i] = 1; //길이가 1이고 마지막숫자가 1~9인 것들에 초기셋팅
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0; //초기화
			if (j - 1 >= 0)dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= 9)dp[i][j] += dp[i - 1][j + 1]; //예외처리
			dp[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)ans += dp[n][i];
	ans %= mod;

	cout << ans << endl;

	return 0;
}