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

string fibo[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibo[0] = "0";
	fibo[1] = "1";

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		string prev1 = fibo[i - 1];
		string prev2 = fibo[i - 2];
		int len1 = prev1.size();
		int len2 = prev2.size();
		
		string cur;
	
		if (len2 < len1) {
			for (int i = 0; i < len1 - len2; i++) {
				prev2.insert(prev2.begin(), '0');
			}
		}

		int prevcarry=0, carry = 0;
		for (int i = len1 - 1; i >= 0; i--) {
			prevcarry = carry;
				if ((prev1[i] - '0') + (prev2[i] - '0') +prevcarry >= 10) {
				carry = 1;
				cur += ((prev1[i] - '0') + (prev2[i] - '0') + prevcarry-10) + '0';
				if (i == 0 && carry != 0) {
					cur += '1';
				}
			}
			else {
					carry = 0;
					cur += ((prev1[i] - '0') + (prev2[i] - '0') + prevcarry) + '0';
			}
		}
		reverse(cur.begin(), cur.end());
		fibo[i] = cur;

	}

	cout << fibo[n] << "\n";

	
	

	
	
	return 0;
}	

