#include <iostream>
#include <algorithm>
using namespace std;

int dp[100 + 1][100 + 1];//���̰� n�̰� ���������ڰ� j�ΰ���Ǽ� (i,j)

int main() {
	int n;
	scanf("%d", &n);
	
	long long mod = 1000000000;

	for (int i = 1; i <= 9; i++) dp[1][i] = 1; //���̰� 1�̰� ���������ڰ� 1~9�� �͵鿡 �ʱ����
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0; //�ʱ�ȭ
			if (j - 1 >= 0)dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= 9)dp[i][j] += dp[i - 1][j + 1]; //����ó��
			dp[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)ans += dp[n][i];
	ans %= mod;

	cout << ans << endl;

	return 0;
}