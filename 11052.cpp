#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000 + 1];
int dp[1000 + 1];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	} //초기화
	
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i-j] + arr[j]);
		}
	}
    //예를들어 3장을 산다고치면 경우의수는 max(3장살때의 가격,2장살때의최대가격+1개살때의가격,1장살때최대가격+2개살떄(p2)의가격)이렇게이다
	printf("%d\n", dp[n]);

}