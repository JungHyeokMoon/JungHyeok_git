// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// using namespace std;
// const int MAX = 65;
// int n;
// int arr[MAX][MAX];
// int ans[3]; //0<=> -1 ì¢…ì´ê°??ˆ˜ ,1<=> 0 ì¢…ì´ê°??ˆ˜ , 2<=> 1 ì¢…ì´ê°??ˆ˜
// bool check(int x, int y, int len) {
// 	int tmp = arr[x][y];
// 	for (int i = x; i < x + len; i++) {
// 		for (int j = y; j < y + len; j++) {
// 			if (tmp != arr[i][j]) return false;
// 		}
// 	}
// 	return true;
// }
// void quad(int x, int y, int len) {
// 	if (check(x, y, len)) {
// 		cout << arr[x][y];
// 	}
// 	else {
// 		cout << "(";
// 		int newlen = len / 2;

// 		quad(x, y, newlen);
// 		quad(x, y + newlen, newlen);
// 		quad(x + newlen, y, newlen);
// 		quad(x + newlen, y + newlen, newlen);
// 		cout << ")";

// 	}
// }
// int main() {
// 	//ios_base::sync_with_stdio(false);
// 	//cin.tie(NULL);
// 	//cout.tie(NULL);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			scanf("%1d", &arr[i][j]);
// 		}
// 	}
// 	quad(0, 0, n);
// 	cout << endl;
// 	return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<char>> MAP;
bool Check(int n, int y, int x)
{
	char first = MAP[y][x];
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (MAP[i][j] != first)
			{
				return false;
			}
		}
	}
	return true;
}
void Init()
{
	cin >> n;
	MAP.resize(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> MAP[i][j];
		}
	}
}
void Recursion(int n, int y, int x)
{
	//base condition
	if (Check(n, y, x))
	{
		cout << MAP[y][x];
		return;
	}
	int divide = n / 2;
	cout << "(";
	Recursion(divide, y, x);
	Recursion(divide, y, x + divide);
	Recursion(divide, y + divide, x);
	Recursion(divide, y + divide, x + divide);
	cout << ")";
}
void Solve()
{
	Recursion(n, 0, 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();
	Solve();
	return 0;
}