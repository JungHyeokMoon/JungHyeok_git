#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int n;
string name;

int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<char, int> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		char temp = name[0];

		m[temp]++;

	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second >= 5) {
			cout << it->first;
			cnt++;
		}
	}

	if (cnt == 0) {
		cout << "PREDAJA" << endl;
	}

	return 0;
}