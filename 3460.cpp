#include <iostream>
#include <vector>
using namespace std;
int t;
int n;
vector<int> v;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;

		while (n != 0) {
			v.push_back(n % 2);
			n = n / 2;
		}
		int k = v.size();
		for (int j = 0; j < k; j++) {
			if (v[j] == 1) {
				cout << j << " ";
			}
		}
		v.clear();
	}

	return 0;
}