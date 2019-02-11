#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.length();
	string *arr;
	arr = new string[n];

	for (int i = 0; i < n; i++) {
		arr[i] = s.substr(i, n);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
	
}