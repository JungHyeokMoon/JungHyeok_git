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
const int MAX = 2200;
int t;
int w;
int arr[10];
int sum = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> w;
		for (int j = 0; j < 9; j++) {
			cin >> arr[j];
			sum += arr[j];
		}
		if (sum <= w) {
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		sum = 0;
	}
	return 0;
}




