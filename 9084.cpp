#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int T; // 테스트케이스
int N; // 동전의가짓수
int M; // 만들어야할금액

int dp[10001];
int coins[21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; i++)
			cin >> coins[i]; //동전입력들끝
		
		cin >> M;
		dp[0] = 1; //j-coins[i] 가 같아지는경우 m과 첫번째 동전의 금액이같아지는경우
		for (int i = 1; i <= N; i++) {
			for (int j = coins[i]; j <= M; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}


		cout << dp[M] << endl;
	}
	
	return 0;

}