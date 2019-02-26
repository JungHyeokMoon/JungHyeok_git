#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	long long c = stoll(a);
	long long d = stoll(b);

	if (c > d) {
		cout << c - d - 1 << '\n';
		for (long long i = d + 1; i < c; ++i) {
			cout << i << ' ';
		}
	}
	else if (c < d) {
		cout << d - c - 1 << '\n';
		for (long long i = c + 1; i < d; ++i) {
			cout << i << ' ';
		}
	}
	else
		cout << 0 << endl;
	printf("\n");

	return 0;
}
