#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int t;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> t;
	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}