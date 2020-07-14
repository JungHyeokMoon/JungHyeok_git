// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <string>
// #include <cstring>
// using namespace std;

// int k;
// vector<int> s;

// vector<int>v;
// /*void dfs(int depth,int num) {
// 	if (depth == 6) {
// 		for (int i = 0; i < depth; i++) {
// 			cout << v[i] << " ";
// 		}
// 		cout << endl;

// 		return;
// 	}

// 	for (int i = num; i < k; i++) {
// 		v.push_back(s[i]);
// 		dfs(depth + 1, i + 1);
// 		v.pop_back();
// 	}

// }*/
// void dfs(int num) {
// 	int n = v.size();
// 	if (n == 6) {
// 		for (int i = 0; i < n; i++) {
// 			cout << v[i] << " ";
// 		}
// 		cout << endl;

// 		return;
// 	}

// 	for (int i = num; i < k; i++) {
// 		v.push_back(s[i]);
// 		dfs(i + 1);
// 		v.pop_back();
// 	}

// }
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	int num;
// 	while (true) {
// 		cin >> k;
// 		if (k == 0) {
// 			break;
// 		}
// 		else {
// 			for (int i = 0; i < k; i++) {
// 				cin >> num;
// 				s.push_back(num);
// 			}
// 			dfs(0);
// 			s.clear();
// 			cout << endl;

// 		}
// 	}
// 	return 0;

// }

#include <bits/stdc++.h>
#define endl "\n"
#define lottoDepth 6
using namespace std;
int k;
vector<int> arr;
vector<int> ret;
vector<bool> visited;
void Init()
{
	arr.clear();
	arr.resize(k);
	ret.clear();
	visited.clear();
	visited.resize(k, false);
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
}

void Recursion(int idx)
{
	if (ret.size() == lottoDepth)
	{
		for (auto i : ret)
		{
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx; i < k; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			ret.push_back(arr[i]);
			Recursion(i + 1);
			ret.pop_back();
			visited[i] = false;
		}
	}
}
void Solve()
{
	while (1)
	{
		cin >> k;
		if (k == 0)
		{
			return;
		}
		Init();
		Recursion(0);
		cout << endl;
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