#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int h, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> h >> m;
	if (h == 0 && m < 45) {
		cout << 23 << " " << 60 - (45 - m) << endl;
	}
	else if (h != 0 && m < 45) {
		cout << h - 1 << " " << 60 - (45 - m) << endl;
	}
	else if (m >= 45) {
		cout << h << " " << m - 45 << endl;
	}
	return 0;
}
