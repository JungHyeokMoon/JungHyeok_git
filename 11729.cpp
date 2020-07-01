// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// using namespace std;

// int n;

// vector<pair<int, int>>v;

// void hanoi(int start, int by, int end, int num) {
// 	if (num == 1) {

// 		//cout << start << " " << end << endl;
// 		v.push_back(make_pair(start, end));
// 	}
// 	else {
// 		hanoi(start, end, by, num - 1);

// 		//cout << start << " " << end << endl;
// 		v.push_back(make_pair(start, end));
// 		hanoi(by, start, end, num - 1);
// 	}
// }
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> n;
// 	hanoi(1,2,3,n);
// 	int cnt = v.size();
// 	cout << cnt << endl;
// 	for (int i = 0; i < cnt; i++) {
// 		cout << v[i].first << " " << v[i].second << '\n';
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
void hanoi(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << " " << b << endl;
		return;
	}
	hanoi(a, 6 - a - b, n - 1);
	cout << a << " " << b << endl;
	hanoi(6 - a - b, b, n - 1);
}
void Solve()
{
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hanoi(1, 3, n);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}