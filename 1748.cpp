#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num = i;

		while (num != 0) {
			cnt++;
			num /= 10;
		}
	}

	cout << cnt << endl;
	return 0;
}
//연속된 정수값찾을때 해결방법