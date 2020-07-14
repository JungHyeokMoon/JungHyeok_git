// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// using namespace std;

// int cnt = 0;
// int n;
// int col[16];

// bool promising(int i) {
// 	for (int k = 1; k < i; k++) {
// 		if (col[i] == col[k] || abs(i - k) == abs(col[i] - col[k])) {
// 			return false;
// 		}
// 	}

// 	return true;

// }

// void nqueen(int i) {
// 	if (promising(i)) {
// 		if (i == n) {
// 			cnt++;
// 			return ;
// 		}
// 		else {
// 			for (int j = 1; j <= n; j++) {
// 				col[i + 1] = j;
// 				nqueen(i + 1);
// 			}
// 		}
// 	}

// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n;
// 	nqueen(0);
// 	cout << cnt << "\n";
// 	return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int ret = 0; //답
int n;
vector<bool> isused1; //같은열
vector<bool> isused2; //왼쪽대각선
vector<bool> isused3; //오른쪽대각선
//cur번째 행에 말을 배치할 예정
void Recursion(int cur)
{
	if (cur == n)
	{
		ret++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isused1[i] && !isused2[cur + i] && !isused3[cur - i + n - 1])
		{
			isused1[i] = true;
			isused2[cur + i] = true;
			isused3[cur - i + n - 1] = true;
			Recursion(cur + 1);
			isused1[i] = false;
			isused2[cur + i] = false;
			isused3[cur - i + n - 1] = false;
		}
	}
}
void Init()
{
	cin >> n;
	isused1.resize(40, false);
	isused2.resize(40, false);
	isused3.resize(40, false);
}
void Solve()
{
	Recursion(0);
	cout << ret << endl;
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