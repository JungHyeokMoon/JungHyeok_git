#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int a, b, c, d, p;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c >> d >> p;
	
	int x = a * p;
	

	int ret = 0;
	if (p <= c) {
		ret = b;
	}
	if (p > c) {
		ret = b + (p - c)*d;
	}
	ret = min(ret, x);

	cout << ret << "\n";
	
	return 0;

}