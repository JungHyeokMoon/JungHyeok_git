#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > ans) //m보다작고 ans를 계속초기화해줌
					ans = arr[i] + arr[j] + arr[k];
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}