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


int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (y <= x && y >= x - 2) {
			if ((x + y) % 2 == 0) {
				if (x % 2 == 1 || y % 2 == 1) {
					cout << x + y - 1 << "\n";
				}
				else {
					cout << x + y << "\n";
				}
			}
			else {
				cout << "No Number" << "\n";
			}
		}
		else {
			cout << "No Number" << "\n";
		}
	}
	
	return 0;
}	