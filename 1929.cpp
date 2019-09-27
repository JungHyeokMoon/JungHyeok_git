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
using namespace std;
long long  m, n;
const int MAX = 1000000;
bool check[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	fill(check, check + MAX+1, true);
	check[1] = false;
	for (int i = 2; (i * i) <= MAX; i++) {
		
		if (check[i]) {
			for (int j = i * i; j <= n; j += i) {
				//cout << j << "번째 수 false" << "\n";
				check[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (check[i]) {
			cout << i << "\n";
		}
	}
	

	return 0;
}