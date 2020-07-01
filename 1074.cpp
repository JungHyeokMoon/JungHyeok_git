// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <math.h>
// using namespace std;
// int n, r, c;
// int cnt = 0;
// void Z(int x, int y,int size) {
// 	if (x == r && y == c) {
// 		cout << cnt << endl;
// 		exit(0);
// 	}
// 	if (size == 1) {
// 		cnt++;
// 		return;
// 	}
// 	else {
// 		if (!(x <= r && r < x + size && y <= c && c < y + size)) {
// 			cnt += size * size;
// 			return;
// 		}
// 		int newsize = size / 2;
// 		Z(x, y, newsize);
// 		Z(x, y + newsize, newsize);
// 		Z(x + newsize, y, newsize);
// 		Z(x + newsize, y + newsize, newsize);

// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> n >> r >> c;
// 	Z(0, 0, (int) pow(2,n));
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, r, c;
int k = 0;
int Recursion(int n, int r, int c) //2^n * 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수
{
	if (n == 0)
	{
		return 0;
	}
	int half = (1 << (n - 1));
	if (r < half && c < half)
		return Recursion(n - 1, r, c);
	if (r < half && c >= half)
		return half * half + Recursion(n - 1, r, c - half);
	if (r >= half && c < half)
		return half * half * 2 + Recursion(n - 1, r - half, c);
	else
		return 3 * half * half + Recursion(n - 1, r - half, c - half);
}
void Solve()
{
	cin >> n >> r >> c;
	cout << Recursion(n, r, c) << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	// cout << (1 << 1) << endl;
	return 0;
}