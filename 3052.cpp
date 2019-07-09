#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int arr[10];
int sol[10];
int cnt = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++) {
		sol[i] = arr[i] % 42;
	}
	sort(sol, sol + 10);
	/*cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << sol[i] << endl;
	}*/
	for (int i = 1; i < 10; i++) {
		if (sol[i] != sol[i - 1])cnt++;
	}
	cout << cnt << endl;
	return 0;
}
