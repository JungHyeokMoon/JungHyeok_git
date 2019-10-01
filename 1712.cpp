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

long long int A, B, C;
long long int s = 1;
long long int e = 2100000001;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B >> C;
	if (C <= B) {
		cout << -1 << "\n";
		return 0;
	}
	long long int multi = C - B;
	while (s <= e) {
		long long int mid = (s + e) / 2;
		
		if (A  < multi* mid) {
			e = mid - 1;
		}
		else {
			s=mid + 1;
		}
	}
	cout << s << "\n";
	return 0;
}	

