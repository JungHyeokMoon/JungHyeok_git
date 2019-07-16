#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;
const int MAX = 1001;
int arr[MAX];
int n, k;
int cnt = 0;
int rem;
int ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}
	while (1) {
		for (int i = 2; i <= n; i++) {
			if (arr[i] != 0) {
				rem = arr[i];
				break;
			}
		}
		
		for (int j = 1; j*rem <= n; j++) {
			if (arr[j*rem] != 0) {
				 ret = arr[j*rem];
				arr[j*rem] = 0;
				cnt++;
			}
			if (k == cnt) {
				cout << ret << endl;
				exit(0);
			}
		}
	}

	return 0;
}




