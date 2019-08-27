#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int cnt = 0;
int n;
int col[16];

bool promising(int i) {
	for (int k = 1; k < i; k++) {
		if (col[i] == col[k] || abs(i - k) == abs(col[i] - col[k])) {
			return false;
		}
	}
	
	return true;
	
}

void nqueen(int i) {
	if (promising(i)) {
		if (i == n) {
			cnt++;
			return ;
		}
		else {
			for (int j = 1; j <= n; j++) {
				col[i + 1] = j;
				nqueen(i + 1);
			}
		}
	}
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	nqueen(0);
	cout << cnt << "\n";
	return 0;
}