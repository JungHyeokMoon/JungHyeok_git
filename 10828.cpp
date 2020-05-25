// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// int main() {
// 	stack<int> stk;
// 	int n;
// 	string s;
// 	scanf("%d", &n);
// 	int num;
// 	for (int i = 0; i < n; i++) {
// 		cin >> s;
// 		if (s == "push") {
// 			scanf("%d", &num);
// 			stk.push(num);
// 			//printf("%d\n", stk.top());
// 		}
// 		else if (s == "pop") {
// 			if (stk.empty())
// 				printf("-1\n");
// 			else {
// 				printf("%d\n", stk.top());
// 				stk.pop();
// 			}
// 		}
// 		else if (s == "size") {
// 			printf("%d\n", stk.size());
// 		}
// 		else if (s == "empty") {
// 			if (stk.empty())
// 				printf("1\n");
// 			else
// 				printf("0\n");
// 		}
// 		else if (s == "top") {
// 			if (stk.empty())
// 				printf("-1\n");
// 			else
// 				printf("%d\n", stk.top());

// 		}
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
void Solve()
{
	stack<int> stk;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int number;
			cin >> number;
			stk.push(number);
		}
		else if (temp == "top")
		{
			if (stk.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stk.top() << endl;
			}
		}
		else if (temp == "size")
		{
			cout << stk.size() << endl;
		}
		else if (temp == "empty")
		{
			if (stk.empty())
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (temp == "pop")
		{
			if (stk.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stk.top() << endl;
				stk.pop();
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}