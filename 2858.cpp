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

int r, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> b;
	for (int i = 3; i<5000; i++) {
		for (int j = 3; j<5000 ; j++) {
			if (2 * i + 2 * j - 4 == r) {
				if (i * j - 2 * i - 2 * j + 4==b) {
					if (i > j) {
						cout << i << " " << j << "\n";
					}
					else {
						cout << j << " " << i << "\n";
					}
					return 0;
				}
			}
		}
	}
	return 0;
}

