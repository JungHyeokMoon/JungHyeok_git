#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;
	int num;
	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		if (num%n == 0) {
			cout << num << " is a multiple of " << n << "." << endl;
		}
		else {
			cout << num << " is NOT a multiple of " << n << "." << endl;
		}
	}

	return 0;
}



