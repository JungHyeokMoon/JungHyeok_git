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
const int MAX = 10000;
bool eratos[MAX + 1];
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	fill(eratos, eratos + MAX+1, true);
	for (int i = 2; i * i <= MAX; i++) {
		if (eratos[i]) {
			for (int j = i * i; j <= MAX; j+=i) {
				eratos[j] = false;
			}
		}
	}
	

	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		for (int j = num / 2; j > 0; j--) {
			if (eratos[j] && eratos[num - j]) {
				cout << j << " " << num - j << "\n";
				break;
			}
		}
	}
	return 0;
}	