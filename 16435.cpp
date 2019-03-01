#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l;
	scanf("%d %d", &n, &l);

	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
		if (arr[i] <= l)
			l++;

	printf("%d\n", l);


	delete[]arr;
	return 0;
}