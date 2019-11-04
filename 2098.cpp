#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;

int n;
int w[16][16];
int dp[16][1 << 16];
//int imposibble = 1000000000;
int tsp(int current, unsigned int visited) {

	int& ret = dp[current][visited];
	if (ret != -1) {
		return ret;
	}

	if (visited == (1 << n) - 1){//모두방문했으면
		if (w[current][0] != 0) {
			return w[current][0];
		}
		return 987654321;

	}

	ret = 987654321;
	for (int node = 0; node< n; node++) {
		if (w[current][node] == 0 || visited & 1 << node  )continue; //가는길이없으면 혹은 가려는곳이방문했으면
		ret = min(ret, tsp(node, (visited | 1 << node)) + w[current][node]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tsp(0, 1));

}