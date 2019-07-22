#include <iostream>
#include <string>
using namespace std;

const int MAX = 10001;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int num = 666;
	int i = 1;
	while (1) {
		if (i == n) {
			break;
		}

		num++;
		int copynum = num;
		string s;
		while (copynum != 0) {
			s += (copynum % 10 + '0');
			copynum /= 10;
		}

		copynum = stoi(s);
		int sixcnt = 0;
		while (copynum != 0) {
			int temp = copynum % 10;
			if (temp == 6) {
				sixcnt++;
			}
			else if (sixcnt < 3) {
				sixcnt = 0;
			}

			copynum /= 10;
		}
		if (sixcnt >= 3) {
			i++;
		}
	}
	
	cout << num;
	return 0;
}
//연속된 정수값찾을때 해결방법