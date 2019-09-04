#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;

int n, m, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	int ret = 0;
	int sum = n + m;
	for (int i = 1; i <= m && i * 2 <= n; i++) {
		if (i + i * 2 + k <= sum)
			ret++;
	}
	
	cout << ret << "\n";
	
	return 0;
}