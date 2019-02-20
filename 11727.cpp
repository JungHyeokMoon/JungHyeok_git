#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000 + 1];//2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� �� �� ���̳������̺����ִ�. dp[n]=dp[n-1]+dp[n-2];

int main(){
	int n;
	scanf("%d" ,&n);

	dp[0] = 1; //2*0 ��ä��¹���� ���������λ����ϰ� �ϳ����ִٰ� �����ؾ���... 
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 2*dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}