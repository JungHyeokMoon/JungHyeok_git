#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 65;
int n;
int arr[MAX][MAX];
int ans[3]; //0<=> -1 종이갯수 ,1<=> 0 종이갯수 , 2<=> 1 종이갯수
bool check(int x, int y, int len) {
	int tmp = arr[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (tmp != arr[i][j]) return false;
		}
	}
	return true;
}
void quad(int x, int y, int len) {
	if (check(x, y, len)) {
		cout << arr[x][y];
	}
	else {
		cout << "(";
		int newlen = len / 2;

		quad(x, y, newlen);
		quad(x, y + newlen, newlen);
		quad(x + newlen, y, newlen);
		quad(x + newlen, y + newlen, newlen);
		cout << ")";

	}
}
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	quad(0, 0, n);
	cout << endl;
	return 0;
}




