#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int l, a, b, c, d;
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> l >> a >> b >> c >> d;

	while (1) {
		if (a <= 0 && b <= 0) {
			break;
		}
		b = b - d;
		a = a - c;
		cnt++;
	}
	cout << l - cnt << endl;
	return 0;
}



