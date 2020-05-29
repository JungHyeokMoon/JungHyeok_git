// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;
// int solution(string s) {
// 	stack<int> stk;
// 	int ans = 0;
// 	for (int i = 0; i < s.size(); i++) {
// 		if (s[i] == '(') {
// 			stk.push(i);
// 		}
// 		else {
// 			if (i - stk.top() == 1) { // �ݴ°�ȣ�ε� top���ִ¼��� 1���̳���
// 				stk.pop();//pop�����ְ� �������������
// 				ans += stk.size();
// 			}
// 			else {
// 				stk.pop();//pop������� ���� �����ִ°����� ������ ����� �����ִ°��̱⶧���̴�
// 				ans += 1;
// 			}
// 		}
// 	}
// 	return ans;
// }
// int main() {
// 	string str;
// 	cin >> str;
// 	cout << solution(str) << endl;
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void Solve()
{
	string str;
	cin >> str;
	stack<char> stk;
	int ret = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			stk.push(i);
		}
		else
		{
			stk.pop();
			if (str[i - 1] != ')')
			{
				ret += stk.size();
			}
			else
			{
				ret += 1;
			}
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