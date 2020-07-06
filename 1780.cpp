// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// using namespace std;
// const int MAX = 2188;
// int n;
// int arr[MAX][MAX];
// int ans[3]; //0<=> -1 ì¢…ì´ê°??ˆ˜ ,1<=> 0 ì¢…ì´ê°??ˆ˜ , 2<=> 1 ì¢…ì´ê°??ˆ˜

// bool check(int x, int y, int len) {
// 	int tmp = arr[x][y];
// 	for (int i = x; i < x + len; i++) {
// 		for (int j = y; j < y + len; j++) {
// 			if (tmp != arr[i][j])return false;
// 		}
// 	}
// 	return true;
// }

// void paper(int x, int y, int len) {
// 	if (check(x, y, len)) {
// 		if (arr[x][y] == -1) {
// 			ans[0] += 1;
// 		}
// 		else if (arr[x][y] == 0) {
// 			ans[1] += 1;
// 		}
// 		else {
// 			ans[2] += 1;
// 		}
// 	}
// 	else {
// 		int newlen = len / 3;
// 		for (int i = 0; i < 3; i++) {
// 			for (int j = 0; j < 3; j++) {
// 				paper(x + i * newlen, y + j * newlen, newlen);
// 			}
// 		}
// 	}
// 	return;
// }
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> n;

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}
// 	paper(0, 0, n);
// 	for (int i = 0; i < 3; i++) {
// 		cout << ans[i] << endl;
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<int>> MAP;
int ret[3] = {0, 0, 0};
void Init()
{
	cin >> n;
	MAP.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> MAP[i][j];
		}
	}
}
bool Check(int n, int y, int x)
{
	int temp = MAP[y][x];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[y + i][x + j] != temp)
				return false;
		}
	}
	return true;
}
void Recursion(int n, int y, int x)
{
	if (Check(n, y, x))
	{
		ret[(MAP[y][x] + 3) % 3]++;
		return;
	}
	int divide = n / 3;
	Recursion(divide, y, x);
	Recursion(divide, y, x + divide);
	Recursion(divide, y, x + divide * 2);
	Recursion(divide, y + divide, x);
	Recursion(divide, y + divide, x + divide);
	Recursion(divide, y + divide, x + 2 * divide);
	Recursion(divide, y + 2 * divide, x);
	Recursion(divide, y + 2 * divide, x + divide);
	Recursion(divide, y + 2 * divide, x + 2 * divide);
}
void Output()
{
	for (int i = 0; i < 3; i++)
	{
		cout << ret[(2 + i) % 3] << endl;
	}
}
void Solve()
{
	Recursion(n, 0, 0);
	Output();
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