#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int main() {
	int n,k;
	scanf("%d %d", &n, &k);

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	nth_element(arr, arr + k-1, arr + n);

	printf("%d\n", arr[k-1]);

	return 0;
}