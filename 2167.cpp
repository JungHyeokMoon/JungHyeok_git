#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 300 + 1;
int n, m;
int k;

int arr[MAX][MAX];
//int sum[MAX][MAX];

int solve(int i1, int j1, int x1, int y1) {
	int sum = 0;
	for (int i = i1; i <= x1; i++) {
		for (int j = j1; j <= y1; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	//memset(sum, -1, sizeof(sum));
	cin >> k;
	for (int v = 0; v < k; v++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << solve(i, j, x, y) << endl;
	}
	return 0;
}



