// #include <iostream>
// #include <deque>
// #include <string>
// using namespace std;

// int main() {
// 	int n;
// 	scanf("%d", &n);
// 	string s;
// 	int num;
// 	deque<int> deq;
// 	while (n--) {
// 		cin >> s;
// 		if (s == "push_front") {
// 			scanf("%d", &num);
// 			deq.push_front(num);
// 		}
// 		else if (s == "push_back") {
// 			scanf("%d", &num);
// 			deq.push_back(num);
// 		}
// 		else if (s == "pop_front") {
// 			if (deq.empty())
// 				printf("-1\n");
// 			else {
// 				printf("%d\n", deq.front());
// 				deq.pop_front();
// 			}
// 		}
// 		else if (s == "pop_back") {
// 			if (deq.empty())
// 				printf("-1\n");
// 			else {
// 				printf("%d\n", deq.back());
// 				deq.pop_back();
// 			}
// 		}
// 		else if (s == "size") {
// 			printf("%d\n", deq.size());
// 		}
// 		else if (s == "empty") {
// 			if (deq.empty())
// 				printf("1\n");
// 			else
// 				printf("0\n");
// 		}
// 		else if (s == "front") {
// 			if (deq.empty()) {
// 				printf("-1\n");
// 			}
// 			else
// 				printf("%d\n", deq.front());
// 		}
// 		else if (s == "back") {
// 			if (deq.empty()) {
// 				printf("-1\n");
// 			}
// 			else
// 				printf("%d\n", deq.back());
// 		}
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
deque<int> dq;
void Solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		int number;
		if (input == "push_back")
		{
			cin >> number;
			dq.push_back(number);
		}
		else if (input == "push_front")
		{
			cin >> number;
			dq.push_front(number);
		}
		else if (input == "pop_front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (input == "size")
		{
			cout << dq.size() << endl;
		}
		else if (input == "empty")
		{
			cout << dq.empty() << endl;
		}
		else if (input == "front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		else
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// Input();
	Solve();
	return 0;
}