#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int n, k;

vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			v.push_back(i);
		}
	}

	if (v.size() < k)cout << 0 << endl;
	else {
		cout << v[k - 1] << endl;
	}
	return 0;
}