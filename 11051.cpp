#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;


int n, k;
long long arr[1001][1001];
long long bino(int N, int K) {
	if (K == 0 || N == K) return 1;
	if (arr[N][K] != -1) {
		return arr[N][K];
	}
	return arr[N][K] = (bino(N-1, K - 1) + bino(N - 1, K))%10007;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	memset(arr, -1, sizeof(arr));
	cin >> n >> k;
	cout << bino(n, k) % 10007 << endl;
	return 0;
}



