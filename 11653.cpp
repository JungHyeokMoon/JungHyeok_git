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
	int i = 2;
	while (n != 0) {
		if (n == 1) break;
		if (n%i == 0) {
			cout << i << endl;
			n = n / i;
		}
		else
			i++;
	}
	return 0;

}