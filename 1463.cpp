#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000000 + 1];//다이나믹테이블 1을만들기위한 최소한의연산수가 들어가있다.  연산을 사용하는 횟수의 최솟값을 출력하시오.
/*int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) //if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1) 여기서 min안에있는 dp[i]는 dp[i] = dp[i - 1] + 1;요거
			dp[i] = dp[i / 2] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) //if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1) 위에와마찬가지로 min안에있는 dp[i] 는 dp[i] = dp[i - 1] + 1;
			dp[i] = dp[i / 3] + 1;
	}
	printf("%d\n", dp[n]);

	return 0;
}*///bottom up

/*int solution(int n) {
	if (n <= 1)
		return 0;
	if (dp[n] > 0)
		return dp[n];
	dp[n] = solution(n - 1) + 1;//n을 n-1로만들어서 1로만드는경우의수
	if (n % 2 == 0) {
		int temp = solution(n / 2) + 1;
		if (dp[n] > temp) dp[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = solution(n / 3) + 1;
		if (dp[n] > temp)dp[n] = temp;
	}
	return dp[n];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", solution(n));

	return 0;

}*/ //topdown