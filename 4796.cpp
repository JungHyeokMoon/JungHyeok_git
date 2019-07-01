#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
int l, p, v;
int j = 1;
int ans = 0;
//int i = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) {
			break;
		}
		else {
			ans = v / p * l;
			if (v-int(v/p)*p>l) {
				ans += l;
			}
			else {
				ans += v % p;
			}

			cout << "Case " << j << ": " << ans << endl;
			ans = 0;
			j++;
		}
		
	}
	
	
	return 0;
}
