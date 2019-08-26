#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int arr[21] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	char token;
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cin >> arr[i];
		else
			cin >> arr[i] >> token;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n- i- 1; j++) {
			arr[j] = arr[j + 1] - arr[j];
		}
	}

	for (int i = 0; i < n - k; i++) {
		if (i == n - k - 1) {
			cout << arr[i];
		}
		else {
			cout << arr[i] << ",";
		}
	}
	return 0;

}