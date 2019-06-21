#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	int row1=0, row2=0, row;
	
	for (int i = a; i > 4; i = i - 4) {
		row1++;
	}
	for (int i = b; i > 4; i = i - 4) {
		row2++;
	}
	
	row = max(row1 - row2, row2 - row1);

	int col1, col2, col;

	col1 = a % 4;
	col2 = b % 4;

	if (col1 == 0)
		col1 = 4;
	if (col2 == 0)
		col2 = 4;

	
	col=max(col1-col2,col2-col1);
	cout << row + col;

}