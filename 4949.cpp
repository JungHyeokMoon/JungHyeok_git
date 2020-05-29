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
// #include <iomanip>
// #include <math.h>
// using namespace std;
// string str;
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	while (1) {
// 		getline(cin,str);
// 		if (str == ".")
// 			break;

// 		stack<char> stk;

// 		int len = str.size();
// 		bool flag = true;
// 		for (int i = 0; i < len; i++) {
// 			if (str[i] == '(' || str[i] == '[')
// 				stk.push(str[i]);
// 			else if (str[i] == ')' || str[i] == ']') {

// 				if (stk.size() == 0) {
// 					flag = false;
// 					break;
// 				}

// 				if (str[i] == ')') {
// 					if (stk.top() != '(') {
// 						flag = false;
// 						break;
// 					}
// 					else {
// 						stk.pop();
// 					}

// 				}
// 				else {
// 					if (stk.top() != '[') {
// 						flag = false;
// 						break;
// 					}
// 					else {
// 						stk.pop();
// 					}
// 				}

// 			}
// 		}

// 		if (stk.size() == 0 && flag) {
// 			cout << "yes" << "\n";
// 		}
// 		else if(stk.size()!=0 || !flag)
// 			cout << "no" << "\n";
// 	}

// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool Discriminate(string str)
{
	stack<char> stk;
	for (auto i : str)
	{
		if (i == '[' || i == '(')
		{
			stk.push(i);
		}
		else if (i == ']')
		{
			if (!stk.empty())
			{
				if (stk.top() == '[')
					stk.pop();
				else
				{
					return false;
				}
			}
			else
				return false;
		}
		else if (i == ')')
		{
			if (!stk.empty())
			{
				if (stk.top() == '(')
					stk.pop();
				else
					return false;
			}
			else
				return false;
		}
	}
	return stk.empty() ? true : false;
}
void Solve()
{
	while (1)
	{
		string str;
		getline(cin, str);
		// cout << str << endl;
		if (str == ".")
			break;
		if (Discriminate(str))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
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