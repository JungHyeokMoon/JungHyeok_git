#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
int n, r, c;
int cnt = 0;
void Z(int x, int y,int size) {
	if (x == r && y == c) {
		cout << cnt << endl; 
		exit(0);
	}
	if (size == 1) {
		cnt++;
		return;
	}
	else {
		if (!(x <= r && r < x + size && y <= c && c < y + size)) {
			cnt += size * size;
			return;
		}
		int newsize = size / 2;
		Z(x, y, newsize);
		Z(x, y + newsize, newsize);
		Z(x + newsize, y, newsize);
		Z(x + newsize, y + newsize, newsize);

	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> r >> c;
	Z(0, 0, (int) pow(2,n));
	return 0;
}




