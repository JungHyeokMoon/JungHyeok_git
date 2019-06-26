#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	if (n == 0) {
		cout << "divide by zero" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << "1.00" << endl;

	}
	return 0;

}