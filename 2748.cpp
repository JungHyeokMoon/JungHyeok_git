#include <iostream>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	long *arr = new long[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 2] + arr[i - 1];

	cout << arr[n] << endl;

	return 0;
}
