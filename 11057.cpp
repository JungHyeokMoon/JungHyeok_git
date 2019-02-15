#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000 + 1][1000 + 1];//���̰� i�̰� ���������� l�� ��������

int main() {
	int n;
	scanf("%d", &n);
	
	int mod = 10007;

	for (int i = 0; i <= 9; i++)dp[1][i] = 1;
	for (int i = 2; i <= n; i++) { //�Է¹�������ŭ������ϸ�Ǵϱ�
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {//dp[i][j]= �ñ׸�dp[i-1][k], 0<=k<=j ����ó���� �ݺ������� �̷������̴�.
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mod;
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i <= 9; i++)ans += dp[n][i]; //���������ǰ����̹Ƿ�
	ans %= mod;

	cout << ans << endl;

	return 0;
}