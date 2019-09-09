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

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0)cnt++;
		if (i % 25 == 0)cnt++;
		if (i % 125 == 0)cnt++;
	}
	
	cout << cnt << "\n";
	
	return 0;
}