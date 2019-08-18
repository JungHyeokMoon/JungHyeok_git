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
const int MAX = 2000000;
int arr[MAX + 1];
int n, c;
int ret = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i <= c; i++) {
		for (int j = 0; j < n; j++) {
			if (i%arr[j]==0) {
				ret++;
				break;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}