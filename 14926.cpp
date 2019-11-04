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

bool crossed[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	crossed[1][n] = crossed[n][1] = true;
	printf("%d %d\n", 1, n);
	int curvertex = 0;
	for (int i = 0; i < (n * (n - 1)) / 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == curvertex || crossed[curvertex][j]) continue;
			crossed[j][curvertex] = crossed[curvertex][j] = true;
			printf("%d %d \n", j, curvertex);
			curvertex = j;
			break;
		}
		printf("a%d ", curvertex);
	}
	printf("a1");

	

	return 0;
}
