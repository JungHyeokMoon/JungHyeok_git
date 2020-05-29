// #include <iostream>
// #include <queue>
// #include <string>
// using namespace std;

// int main() {
// 	int n;
// 	scanf("%d", &n);
// 	string s;
// 	int num;
// 	queue<int> q;
// 	while (n--) {
// 		cin >> s;
// 		if (s == "push") {
// 			scanf("%d", &num);
// 			q.push(num);
// 		}
// 		else if (s == "pop") {
// 			if (q.empty()) {
// 				printf("-1\n");
// 			}
// 			else {
// 				printf("%d\n", q.front());
// 				q.pop();
// 			}
// 		}
// 		else if (s == "size") {
// 			printf("%d\n", q.size());
// 		}
// 		else if (s == "empty") {
// 			if (q.empty())
// 				printf("1\n");
// 			else
// 				printf("0\n");
// 		}
// 		else if (s == "front") {
// 			if (q.empty())
// 				printf("-1\n");
// 			else
// 				printf("%d\n", q.front());
// 		}
// 		else if (s == "back") {
// 			if (q.empty())
// 				printf("-1\n");
// 			else
// 				printf("%d\n", q.back());
// 		}
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
queue<int> q;
void Solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (input == "front")
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.front() << endl;
			}
		}
		else if (input == "back")
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.back() << endl;
			}
		}
		else if (input == "size")
		{
			cout << q.size() << endl;
		}
		else if (input == "pop")
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else
		{
			cout << q.empty() << endl;
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