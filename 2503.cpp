#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1000;
bool ansarr[MAX] ;
string s, comp1, comp2;

int ret = 0;
int n,number, strike, ball;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(ansarr, true, sizeof(ansarr));
	for (int i = 123; i <= 987; i++) {
		 s = to_string(i);
		if (s[0] - '0'==0 || s[1] - '0'==0 || s[2] -'0'==0) {
			ansarr[i] = false;
		}
		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) {
			ansarr[i] = false;
		}
	} //초기화
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number >> strike >> ball;
		for (int j = 123; j <= 987; j++) {
			int scount = 0;
			int bcount = 0;
			if (ansarr[j]) {
				 comp1 = to_string(number);
				 comp2 = to_string(j);
				
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y && comp1[x] == comp2[y])scount++;
						if (x != y && comp1[x] == comp2[y])bcount++;
					}
				}
				if (scount != strike || ball != bcount)ansarr[j] = false;
			}
			
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (ansarr[i])ret++;
	}
	cout << ret << endl;
	return 0;
	
}
