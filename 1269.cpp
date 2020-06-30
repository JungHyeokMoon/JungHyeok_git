// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// #include <stack>
// using namespace std;

// const int MAX = 200000;
// int A[MAX + 1], B[MAX + 1];
// int intersection = 0;
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int a, b;
// 	cin >> a >> b;
// 	for (int i = 0; i < a; i++) {
// 		cin >> A[i];
// 	}
// 	for (int i = 0; i < b; i++) {
// 		cin >> B[i];
// 	}

// 	sort(A, A + a);
// 	for (int i = 0; i < b; i++) {
// 		if (binary_search(A, A + a, B[i])) {
// 			intersection++;
// 		}
// 	}

// 	cout << a + b - intersection * 2 << "\n";
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int A, B, C;
long long calc(int a, int b, int c)
{
	if (b == 1)
		return a;
	long long ret = calc(a, b / 2, c) % c;
	if (b % 2 == 0)
	{
		return (ret * ret) % c;
	}
	else
	{
		return ((ret * ret) % c * a) % c;
	}
}
void Solve()
{
	cin >> A >> B >> C;
	cout << calc(A, B, C) % C << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}