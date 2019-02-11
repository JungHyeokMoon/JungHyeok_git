#include <iostream>
using namespace std;
int dp[100];
int fibo(int n) {
	if (n <= 1)
		return n;
	else {
		if (dp[n] > 0)return dp[n];
		dp[n] = fibo(n - 2) + fibo(n - 1);
		return dp[n];
	}
		
		
}

int main() {
	int n;
	scanf("%d", &n);

	cout << fibo(n) << endl;

	return 0;
}