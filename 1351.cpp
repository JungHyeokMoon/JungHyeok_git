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

map<long long, long long >m;
long long n, p, q;

long long solve(long long n, long long &p ,long long &q) {
	if (n == 0)
		return 1;
	if (m[n])
		return m[n];
	return m[n] = solve(n / p, p, q) + solve(n / q, p, q);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p >> q;
	cout << solve(n, p, q) << "\n";
	

	return 0;
}
