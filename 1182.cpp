// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// using namespace std;

// int n, s;

// vector<int> v;
// int ret = 0;

// void dfs(int num, int pos) {
// 	if (pos == n)
// 		return;
// 	if (num+v[pos] == s)
// 		ret++;

// 	dfs(num , pos + 1);
// 	dfs(num + v[pos], pos + 1);
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	std::cout.tie(NULL);

// 	cin >> n >> s;
// 	v.resize(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> v[i];
// 	}

// 	dfs(0, 0);
// 	cout << ret << endl;
// 	return 0;

// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, s;
vector<int> arr;

int ret = 0;
void Init()
{
	cin >> n >> s;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void Recursion(int k, int sum)
{
	if (k == n)
	{
		return;
	}
	if (sum + arr[k] == s)
	{
		ret++;
	}
	Recursion(k + 1, sum + arr[k]);
	Recursion(k + 1, sum);
}
void Solve()
{
	Recursion(0, 0);
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