#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int m;
bool arr[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	arr[1] = true;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= 3; i++) {
		if (arr[i] == true) {
			cout << i << endl;
			break;
		}
	}
	return 0;
	
}
