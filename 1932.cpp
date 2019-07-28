#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;


int n;
const int MAX = 501;
int triangle[MAX][MAX];
int cache[MAX][MAX];
int sum = 0;
int solve(int y, int x) {
	if (y == n - 1) return triangle[y][x];
	int &ret = cache[y][x];
	if (ret != -1)return ret;
	return ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + triangle[y][x];
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	cout << solve(0, 0) << endl;
	return 0;
}



