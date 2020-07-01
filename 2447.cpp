// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <string.h>
// #include <math.h>
// using namespace std;
// const int MAX = 2200;
// char arr[MAX][MAX];
// int n;
// void star(int x, int y,int size) {
// 	if (size == 1) {
// 		arr[x][y] = '*';
// 		return;
// 	}
// 	else {
// 		int newsize = size / 3;
// 		star(x, y, newsize);
// 		star(x, y + newsize, newsize);
// 		star(x, y + 2 * newsize, newsize);
// 		star(x + newsize, y, newsize);
// 		//?•„ë¬´ê²ƒ?„?•ˆ?•˜?Š”ê³µë°±
// 		star(x + newsize, y + 2 * newsize, newsize);
// 		star(x + 2 * newsize, y , newsize);
// 		star(x + 2 * newsize, y +   newsize, newsize);
// 		star(x + 2 * newsize, y + 2 * newsize, newsize);
// 	}
// }
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n;

// 	memset(arr, ' ', sizeof(arr));
// 	star(0, 0, n);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cout << arr[i][j];
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<vector<char>> MAP;
char star[3][3] = {
	{'*', '*', '*'},
	{'*', ' ', '*'},
	{'*', '*', '*'}};

void func(int n, int r, int c)
{
	if (n == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				MAP[r + i][c + j] = star[i][j];
			}
		}
		return;
	}
	int divide = n / 3;

	func(divide, r, c);
	func(divide, r, c + divide);
	func(divide, r, c + divide * 2);
	func(divide, r + divide, c);
	func(divide, r + divide, c + divide * 2);
	func(divide, r + divide * 2, c);
	func(divide, r + divide * 2, c + divide);
	func(divide, r + divide * 2, c + divide * 2);
}
void Output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << MAP[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void Solve()
{
	cin >> n;
	MAP.resize(n, vector<char>(n, ' '));
	func(n, 0, 0);
	Output();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}