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

int a, b, c, d;
int sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c >> d;
	sum = a + b + c + d;

	cout << sum / 60 << "\n";
	cout << sum % 60 << "\n";

	return 0;
}