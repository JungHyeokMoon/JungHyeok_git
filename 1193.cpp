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
int x;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x;
	int line = 0;
	int sum = 0;
	while (sum + line < x) {
		sum += line++;
	}

	int a, b;
	if (line % 2 == 0) {
		a = x - sum;
	}
	else {
		a = line + 1 - (x - sum);
	}
	b = line + 1 - a;
	cout << a << "/" << b << "\n";

	

	
	return 0;
}