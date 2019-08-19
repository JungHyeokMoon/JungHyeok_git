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

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int >v(3, 0);
	while (1) {
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		a = v[0], b = v[1], c = v[2];
		if ((a == 0 && b == 0) && c == 0)
			break;

		if (a*a + b * b == c * c) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}


	return 0;
}