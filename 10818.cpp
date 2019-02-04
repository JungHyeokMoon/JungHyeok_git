#include <iostream>
#include <algorithm>

int main() {
	int *arr;
	int n;
	scanf("%d", &n);
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + n);
	printf("%d %d\n", arr[0], arr[n - 1]);

	return 0;

}