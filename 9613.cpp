#include <iostream>
#include <algorithm>
using namespace std;

int arr[100 + 1];

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		long long sum = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}//이부분을구현
		

		cout << sum << endl;

	}

	return 0;
}