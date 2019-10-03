#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;
long long A, B, V;

const int MAX = 1000000000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> V;
	long long s = 0;
	long long e = MAX+1;
	long long dist = A - B;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long h = mid * dist;
		if (h >= V - A) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}

	}

	cout << s + 1 << "\n";
	
	return 0;
}	

