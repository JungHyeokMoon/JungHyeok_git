#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	long long N;
	int B;

	string s = "";

	cin >> N;
	
	scanf("%d", &B);

	while (N != 0) {
		int d = N % B;
		if (10 <= d && d <= 35) {
			s += char(d -10+'A');
		}
		else {
			s += char(d + '0');
		}
		N = N / B;
	}

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}
