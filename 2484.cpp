#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int price;
	int result = 0;
	while (n--) {
		int arr[4];
		for (int i = 0; i < 4; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + 4);

		if (arr[0] == arr[3])
			price = 50000 + arr[0] * 5000;
		else if (arr[0] == arr[2] || arr[1] == arr[3])
			price = 10000 + arr[1] * 1000;
		else if (arr[0] == arr[1] && arr[2] == arr[3])
			price = 2000 + arr[0] * 500 + arr[2] * 500;
		else if (arr[0] == arr[1] || arr[1] == arr[2])
			price = 1000 + arr[1] * 100;
		else if (arr[2] == arr[3])
			price = 1000 + arr[2] * 100;
		else
			price = 100 * arr[3];

		result = max(result, price);
	}
	printf("%d", result);
	return 0;
}