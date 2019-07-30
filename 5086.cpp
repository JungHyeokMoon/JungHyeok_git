#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int a, b;

int main() {
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		if (b%a == 0) {
			cout << "factor" << endl;
		}
		else if (a%b == 0) {
			cout << "multiple" << endl;
		}
		else
			cout << "neither" << endl;
	}
}