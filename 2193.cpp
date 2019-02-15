#include <iostream>
#include <algorithm>
using namespace std;

long long dp[90 + 1][90 + 1];// i자리의 이친수의개수 j번째에 0,1둘중하나

int main() {
	int n;
	scanf("%d", &n);

	dp[1][0] = 0;
	dp[1][1] = 1;//1자리수에서 앞자리가 0으로 시작할수없으니 이렇게됨

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; //i번째자리에 0이오면 앞에는 0,1 둘다가능 n-1이친수가가능하다이소리
		dp[i][1] = dp[i - 1][0];//i번째자리에 1이오면 앞에는 0만가능이라서 
	}
	cout << dp[n][0] + dp[n][1] << endl;

	return 0;
}