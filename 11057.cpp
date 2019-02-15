#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000 + 1][1000 + 1];//길이가 i이고 마지막수가 l인 오르막수

int main() {
	int n;
	scanf("%d", &n);
	
	int mod = 10007;

	for (int i = 0; i <= 9; i++)dp[1][i] = 1;
	for (int i = 2; i <= n; i++) { //입력받은수만큼만계산하면되니깐
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {//dp[i][j]= 시그마dp[i-1][k], 0<=k<=j 예외처리가 반복문에서 이뤄진것이다.
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mod;
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i <= 9; i++)ans += dp[n][i]; //오르막수의갯수이므로
	ans %= mod;

	cout << ans << endl;

	return 0;
}