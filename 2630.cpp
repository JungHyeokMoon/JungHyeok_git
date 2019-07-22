#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
const int MAX = 129;
int arr[MAX][MAX];
int wcnt = 0;
int bcnt = 0;
void sol(int x, int y, int size) {
	if (size == 1) {
		if (arr[x][y]==0)wcnt++;
		else bcnt++;
		return;
	}
	
	else {
		int tmp = arr[x][y];
		bool ok = true;
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (tmp != arr[i][j]) {
					ok = false;
					break;
				}
				if (ok == false)
					break;
			}
		}
		if (ok) {
			if (tmp == 0)wcnt++;
			else bcnt++;
		}
		else {
			sol(x, y, size / 2);
			sol(x + size / 2, y, size / 2);
			sol(x, y + size / 2, size / 2);
			sol(x + size / 2, y + size / 2, size / 2);
		}
	}
	
	
	
	//if (tmp == 0)wcnt = wcnt ++;
	//else bcnt = bcnt ++;
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	sol(0, 0, n);
	cout << wcnt << endl << bcnt << endl;
}
//연속된 정수값찾을때 해결방법