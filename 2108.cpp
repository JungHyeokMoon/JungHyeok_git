#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;

int n;
const int MAX = 500000;
int arr[MAX + 1];
map<int, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	double sum = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		m[arr[i]]++;
	}

	
	cout << (int)floor((sum / n) + 0.5) << "\n";
	sort(arr, arr + n);
	cout << arr[n / 2] << "\n";
	int mode = -987654321;
	int ret = 0;
	map<int, int>::iterator it;
	for ( it = m.begin(); it != m.end(); it++) {
		if (mode < it->second) {
			mode = it->second;
			ret = it->first;
		}
	}
	int cnt = 0;
	for (it = m.begin(); it != m.end(); it++) {
		if (mode == it->second) {
			cnt++;
			ret = it->first;
			if (cnt == 2)break;
		}
	}
	cout << ret << "\n";
	
	cout << arr[n - 1] - arr[0] << "\n";

	return 0;
}