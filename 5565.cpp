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

int sum;
int book;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> sum;
	for (int i = 0; i < 9; i++) {
		cin >> book;
		sum = sum - book;
	}

	cout << sum << "\n";

	return 0;
}