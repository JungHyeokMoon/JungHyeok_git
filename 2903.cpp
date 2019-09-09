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

	int points = 2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		points = points * 2 - 1;
	}
	cout << points * points << "\n";
	
	
	return 0;
}