#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;
const int MAX = 2200;
char arr[MAX][MAX];
int n;
void star(int x, int y,int size) {
	if (size == 1) {
		arr[x][y] = '*';
		return;
	}
	else {
		int newsize = size / 3;
		star(x, y, newsize);
		star(x, y + newsize, newsize);
		star(x, y + 2 * newsize, newsize);
		star(x + newsize, y, newsize);
		//아무것도안하는공백
		star(x + newsize, y + 2 * newsize, newsize);
		star(x + 2 * newsize, y , newsize);
		star(x + 2 * newsize, y +   newsize, newsize);
		star(x + 2 * newsize, y + 2 * newsize, newsize);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	memset(arr, ' ', sizeof(arr));
	star(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}




