#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int year;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> year;

	if (year % 4 == 0 && year%100!=0) {
		cout << 1 << endl;
	}
	else if (year%400==0){//year % 4 == 0 && year % 400 == 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
