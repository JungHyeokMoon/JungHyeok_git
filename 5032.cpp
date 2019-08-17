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

int e, f, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> e >> f >> c;
	int sum = e + f;
	int ret = 0;
	
	while (sum != 0) {

		if (sum < c) break;
		ret += sum / c;
		sum = sum / c + sum % c;
	}

	cout << ret << "\n";
	
	return 0;
}