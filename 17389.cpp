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
string OX;
int bonus = 0;
int sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> OX;
	for (int i = 0; i < n; i++) {
		if (OX[i] == 'X') {
			bonus = 0;
		}
		else {
			sum += i + 1;
			sum += bonus;
			bonus++;
		}
	}

	cout << sum << "\n";

	return 0;
}