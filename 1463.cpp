#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000000 + 1];//���̳������̺� 1����������� �ּ����ǿ������ ���ִ�.  ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
/*int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) //if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1) ���⼭ min�ȿ��ִ� dp[i]�� dp[i] = dp[i - 1] + 1;���
			dp[i] = dp[i / 2] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) //if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1) �����͸��������� min�ȿ��ִ� dp[i] �� dp[i] = dp[i - 1] + 1;
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
	dp[n] = solution(n - 1) + 1;//n�� n-1�θ��� 1�θ���°���Ǽ�
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