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

int n;

int bulb[18];
int simul[18];

void push(int y, int x) {
	//제자리
	simul[y] ^= (1 <<( n - x - 1));
	//위쪽
	if(y-1>=0)
		simul[y-1]^= (1 << (n - x - 1));
	//아래쪽
	if(y+1<=n-1)
		simul[y+1]^= (1 << (n - x - 1));
	//왼쪽
	if(x-1>=0)
		simul[y]^= (1 << (n - x ));
	//오른쪽
	if (x + 1 <= n - 1)
		simul[y] ^= (1 << (n - x - 2));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >= 0; j--) {
			int temp;
			cin >> temp;
			if (temp) {
				bulb[i] |= (1 << j);
			}
		}
	}

	int result = 987654321;

	for (int i = (1 << n) - 1; i >= 0; i--) {
		
		for (int j = 0; j < n; j++) {
			simul[j] = bulb[j];
		}
		int count = 0; 
		for (int x = 0; x < n; x++) {
			if (i & 1<<(n - x - 1)) {
				push(0, x);
				count++;
			}
		}//위에는 다눌렀고

		for (int y = 1; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (simul[y - 1] && simul[y - 1] & (1 << (n - x - 1))) {
					push(y, x);
					count++;
				}
			}
		}

		if (!simul[n - 1]) {
			result = min(result, count);
		}
		

	}

	if (result == 987654321) {
		cout << -1 << "\n";
	}
	else {
		cout << result << "\n";
	}

	

}