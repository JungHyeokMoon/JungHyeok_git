#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	
	int A, B;
	cin >> A >> B;
	int lb = B;
	while (B != 0) {
		cout << (B % 10)*A << endl;
		B /= 10;
	}
	
	cout << A * lb << endl;
	return 0;
}