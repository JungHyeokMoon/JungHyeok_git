// #pragma warning(disable:4996)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <stack>
// #include <string>
// #include <cmath>
// #include <queue>
// #include <cstdlib>
// #include <map>
// #include <deque>
// using namespace std;

// int n, m;

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	deque<int >dq;

// 	cin >> n >> m;
// 	for (int i = 1; i <= n; i++) {
// 		dq.push_back(i);
// 	}

// 	int ret = 0;
// 	for(int i=0; i<m; i++){
// 		int num;
// 		cin >> num;
// 		int front = 0;
// 		int back = 0;
// 		for (auto p = dq.begin(); p != dq.end(); p++) {
// 			if (*p == num)
// 				break;
// 			front++;
// 		}
// 		back = dq.size() - front - 1;
// 		if (front <= back) {
// 			for (int j = 1; j <= front; j++) {
// 				dq.push_back(dq.front());
// 				dq.pop_front();
// 				ret++;
// 			}
// 		}
// 		else {
// 			for (int j = 0; j <= back; j++) {
// 				dq.push_front(dq.back());
// 				dq.pop_back();
// 				ret++;
// 			}
// 		}
// 		dq.pop_front();
// 	}

// 	cout << ret << "\n";

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m; //큐의크기 n 뽑아내려고하는 수의개수 m
vector<int> idx;
deque<int> dq;
int ret = 0;
void Init()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
}
// void Output()
// {
// 	for (auto i = dq.begin(); i != dq.end(); i++)
// 	{
// 		cout << *i << " ";
// 	}
// 	cout << endl;
// }
void Solve()
{
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		int front = 0, back = 0;
		for (auto i = dq.begin(); i != dq.end(); i++)
		{
			if (*i == num)
			{
				break;
			}
			front++;
		}
		back = dq.size() - front - 1;

		if (front <= back)
		{
			for (int i = 0; i < front; i++)
			{
				dq.push_back(dq.front());
				ret++;
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0; i <= back; i++)
			{
				dq.push_front(dq.back());
				ret++;
				dq.pop_back();
			}
		}
		dq.pop_front();
		// Output();
	}
	cout << ret << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();
	Solve();
	return 0;
}
