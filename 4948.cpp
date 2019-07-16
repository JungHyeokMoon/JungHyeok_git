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
int arr[246913];
int cnt = 0;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	arr[1] = 1;
	for (int i = 2; i <= 246912; i++) {
		if (arr[i] == 1)continue;
		for (int j = i + i; j <= 246912; j = j + i) {
			arr[j] = 1;
		}
	}


	while (1) {
		cin >> n;
		if (n == 0) {
			exit(0);
		}
		for (int i = n+1; i <= 2 * n; i++) {
			if (arr[i] == 0) {
				cnt++;
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
	
	return 0;
}




