#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
const int MAX = 10000000 + 1;
long long arr[MAX];

long long solve(int n) {
	arr[1] = 5;
	if (n == 1) {
		return arr[n];
	}
	else {
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + (i * 3) + 1;
		}
	}
	return arr[n];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	
	cin >> n; 
	cout << (solve(n) % 45678) << endl;
	return 0;
}


