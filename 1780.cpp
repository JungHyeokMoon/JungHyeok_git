#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 2188;
int n;
int arr[MAX][MAX];
int ans[3]; //0<=> -1 종이갯수 ,1<=> 0 종이갯수 , 2<=> 1 종이갯수

bool check(int x, int y, int len) {
	int tmp = arr[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (tmp != arr[i][j])return false;
		}
	}
	return true;
}


void paper(int x, int y, int len) {
	if (check(x, y, len)) {
		if (arr[x][y] == -1) {
			ans[0] += 1;
		}
		else if (arr[x][y] == 0) {
			ans[1] += 1;
		}
		else {
			ans[2] += 1;
		}
	}
	else {
		int newlen = len / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				paper(x + i * newlen, y + j * newlen, newlen);
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	paper(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}




