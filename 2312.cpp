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
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		map<int, int> m;
		int j = 2;
		while (num != 1) {
			
			if (num % j == 0) {
				num = num / j;
				m[j]++;
			}
			else
				j++;
		}
		for (auto i = m.begin(); i != m.end(); i++) {
			cout << i->first << " " << i->second << "\n";
		}
	}
	

	return 0;
}