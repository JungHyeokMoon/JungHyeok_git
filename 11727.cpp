#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000 + 1];//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수 가 다이나믹테이블에있다. dp[n]=dp[n-1]+dp[n-2];

int main(){
	int n;
	scanf("%d" ,&n);

	dp[0] = 1; //2*0 을채우는방법을 공집합으로생각하고 하나가있다고 생각해야함... 
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 2*dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}