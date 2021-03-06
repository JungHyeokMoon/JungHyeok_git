#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int n;
	int A, B;

	scanf("%d", &n);

	while (n--) {
		scanf("%d %d", &A, &B);

		printf("%d\n", (A*B) / gcd(A, B));
	}
	return 0;
}
