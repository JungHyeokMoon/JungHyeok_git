#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int arr[7];
	for (int i = 0; i < 7; i++)
		scanf("%d", &arr[i]);

	vector<int> odd;
	for (int i = 0; i < 7; i++) {
		if (arr[i] % 2 != 0)
			odd.push_back(arr[i]);
	}
	if (!odd.empty()) {
		int len = odd.size();
		int sum = 0;
		sort(odd.begin(), odd.end());
		for (int i = 0; i < len; i++) {
			sum = sum + odd[i];
		}

		printf("%d\n%d\n", sum, odd[0]);
	}
	else {
		printf("-1\n");
	}
	return 0;
}