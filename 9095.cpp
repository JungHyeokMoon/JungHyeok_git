#include <iostream>
#include <algorithm>
using namespace std;

int dp[10 + 1];// 정수 n을 1,2,3의 조합으로 나타내는 방법의 수를 구하는 문제

int main() {
	int t;
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int n;
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;

}
