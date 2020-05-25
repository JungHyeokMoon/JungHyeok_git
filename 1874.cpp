// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <stack>
// #include <string>
// using namespace std;

// int n;
// const int MAX = 100000;
// int arr[MAX];
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}
// 	vector<char> op;
// 	stack<int> stk;
// 	int num = 0;
// 	for (int i = 0; i < n; i++) {
// 		while (1) {
// 			if (num >= arr[i])
// 				break;
// 			else {
// 				stk.push(++num);
// 				op.push_back('+');
// 			}
// 		}
// 		if (arr[i] == stk.top()) {
// 			stk.pop();
// 			op.push_back('-');
// 		}
// 		else if (arr[i] < stk.top()) {
// 			cout << "NO" << "\n";
// 			return 0;
// 		}

// 	}

// 	int len = op.size();
// 	for (int i = 0; i < len; i++) {
// 		cout << op[i] << "\n";
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<int> arr;
string str;
void Input()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void Solve()
{
	int idx = 0;
	stack<int> stk;
	for (auto i : arr)
	{
		while (idx < i)
		{
			stk.push(++idx);
			str.push_back('+');
		}
		if (stk.top() == i)
		{
			stk.pop();
			str.push_back('-');
		}
		else
		{
			cout << "NO";
			return;
		}
	}
	for (auto i : str)
	{
		cout << i << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solve();
	return 0;
}