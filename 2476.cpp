#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int ans = 0;
	scanf("%d", &n);
	int arr[3];
	while (n--) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		sort(arr, arr + 3);
		if ((arr[0] == arr[1])&&(arr[1] == arr[2])) {
			ans = max(ans, 10000 + arr[0] * 1000);
		}
		else if ((arr[0] == arr[1]) || (arr[0] == arr[2]) || (arr[1] == arr[2])) {
			ans = max(ans, 1000 + arr[1] * 100);
		}
		else {
			ans = max(ans, arr[2] * 100);
		}

	}
	printf("%d\n", ans);
	return 0;
}