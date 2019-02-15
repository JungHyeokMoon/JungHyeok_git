#include <iostream>
#include <algorithm>
using namespace std;

long long dp[90 + 1][90 + 1];// i�ڸ��� ��ģ���ǰ��� j��°�� 0,1�����ϳ�

int main() {
	int n;
	scanf("%d", &n);

	dp[1][0] = 0;
	dp[1][1] = 1;//1�ڸ������� ���ڸ��� 0���� �����Ҽ������� �̷��Ե�

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; //i��°�ڸ��� 0�̿��� �տ��� 0,1 �Ѵٰ��� n-1��ģ���������ϴ��̼Ҹ�
		dp[i][1] = dp[i - 1][0];//i��°�ڸ��� 1�̿��� �տ��� 0�������̶� 
	}
	cout << dp[n][0] + dp[n][1] << endl;

	return 0;
}