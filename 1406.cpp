// #include <iostream>
// #include <stack>
// #include <cstring>
// using namespace std;

// char a[600000];
// int main(){
// 	stack<char> stk1;
// 	stack<char> stk2;

// 	scanf("%s", a);
// 	int n = strlen(a);

// 	for (int i = 0; i < n; i++) {
// 		stk1.push(a[i]);
// 	}

// 	int m;
// 	scanf("%d", &m); // �ݺ��� ���� �Է�

// 	while(m--){
// 		char command;
// 		scanf(" %c", &command);
// 		if (command == 'L') {
// 			if (!stk1.empty()) {//stk1�� �������������� �� Ŀ���� �Ǿտ��ִ°�찡�ƴ϶��
// 				stk2.push(stk1.top());
// 				stk1.pop();
// 			}
// 		}	else if (command == 'D') {
// 			if (!stk2.empty()) {
// 				stk1.push(stk2.top());
// 				stk2.pop();
// 			}
// 		}	else if (command == 'B') {
// 			if (!stk1.empty()) {
// 				stk1.pop();
// 			}
// 		}	else if (command == 'P') {
// 			char c;
// 			scanf(" %c", &c);
// 			stk1.push(c);
// 		}
// 	}

// 	while (!stk1.empty()) {
// 		stk2.push(stk1.top());
// 		stk1.pop();
// 	}

// 	while (!stk2.empty()) {
// 		printf("%c", stk2.top());
// 		stk2.pop();
// 	}
// 	cout << endl;
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string str;
list<char> L;
int M;
list<char>::iterator it;
void Input()
{
	cin >> str;
	it = L.begin();
	for (int i = 0; i < str.size(); i++)
	{
		L.push_back(str[i]);
		// it++;
	}
	// it++;
	it = L.end();
}
void Output()
{
	for (auto i : L)
	{
		cout << i;
	}
	cout << endl;
}
void Solve()
{
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'P')
		{
			char input;
			cin >> input;
			L.insert(it, input);
			// cout << *it << endl;
		}
		else if (cmd == 'L')
		{
			if (it != L.begin())
			{
				it--;
			}
			// cout << *it << endl;
		}
		else if (cmd == 'D')
		{
			if (it != L.end())
			{
				it++;
			}
			// cout << *it << endl;
		}
		else
		{
			// if (it == L.end())
			if (it != L.begin())
			{
				it--;
				it = L.erase(it);
			}

			// cout << *it << endl;
			// Output();
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solve();
	Output();
	return 0;
}