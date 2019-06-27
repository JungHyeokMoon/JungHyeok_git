#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int h;
long long arr[61];
long long solve(int h) {
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= h; i++) {
		if (i % 2 == 0) {
			arr[i] = arr[i - 1] * 2+1;
		}
		else {
			arr[i] = arr[i - 1] * 2 - 1;
		}
	}
	
	return arr[h];

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> h;
	cout << solve(h) << endl;
	return 0;

}