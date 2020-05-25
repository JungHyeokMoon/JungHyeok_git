// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// using namespace std;

// int k;
// stack<int> stk;
// int sum = 0;
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> k;
// 	for (int i = 0; i < k; i++) {
// 		int num;
// 		cin >> num;
// 		if (num != 0) {
// 			stk.push(num);
// 		}
// 		else {
// 			stk.pop();
// 		}
// 	}
// 	while (!stk.empty()) {
// 		sum += stk.top();
// 		stk.pop();
// 	}
// 	cout << sum << endl;

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int k;
int ret = 0;
void Solve()
{
	stack<int> stk;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int number;
		cin >> number;
		if (number == 0)
		{
			ret -= stk.top();
			stk.pop();
		}
		else
		{
			ret += number;
			stk.push(number);
		}
	}

	cout << ret << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}
