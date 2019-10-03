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
int M, N, x, y;
int t;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> M >> N >> x >> y;

		int maxyear = lcm(M, N);
		int j;
		for ( j = x; j <= maxyear; j += M) {
			int temp = (j % N == 0) ? N : j % N;
			if (temp == y) {
				cout << j << "\n";
				break;
			}
		}
		if (j > maxyear) {
			cout << -1 << "\n";
		}
	}
	return 0;
}	

