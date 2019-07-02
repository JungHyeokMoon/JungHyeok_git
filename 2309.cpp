#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 10;
int arr[MAX];
int j, k = 0;
int sum = 0;
bool flag = false;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (j = 0; j < 9; j++) {
		for (k = j + 1; k < 9; k++) {
			if (sum - arr[j] - arr[k] == 100) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			break;
		}
	}
	arr[j] = 0;
	arr[k] = 0;
	sort(arr, arr + 9);
	for (int i = 2; i < 9; i++) {
		cout << arr[i] << endl;
	}
	
	return 0;
	
}
