// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;
// string solution(string s) {
// 	int cnt = 0;
// 	for (int i = 0; i < s.size(); i++) {
// 		if (s[i] == '(') {
// 			cnt += 1;
// 		}
// 		else {//�ݴ°�ȣ�ǰ��
// 			cnt -= 1;
// 			if (cnt < 0)
// 				return "NO";
// 		}

// 	}
// 	if (cnt == 0)
// 		return "YES";
// 	else
// 		return "NO";

// }
// int main() {
// 	stack<char> stk;
// 	int n;
// 	scanf("%d", &n);
// 	string s;
// 	for (int i = 0; i < n; i++) {
// 		cin >> s;
// 		cout << solution(s) << endl;

// 	}

// 	return 0;
// }
// #include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool Discriminate(string str)
{
	stack<char> stk;
	// cout << str << endl;
	for (int i = 0; i < str.size(); i++)
	{
		char blancket = str[i];
		if (blancket == '(')
		{
			stk.push(blancket);
		}
		else
		{
			if (stk.empty())
				return false;
			stk.pop();
		}
	}
	return stk.empty() == 1 ? true : false;
}
void Solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (Discriminate(str))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
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