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

int n;
const int MAX = 1000;
int dp[MAX + 1];
int arr[MAX + 1];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		dp[i] = 1;

	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}

	cout << ret << "\n";

	return 0;
}