// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;
// int n, m;
// vector<int> arr;

// void p(int idx, int depth) {
// 	if (depth == m) {
// 		for (int i = 0; i < arr.size(); i++) {
// 			cout << arr[i] << " ";
// 		}
// 		cout <<'\n';
// 		return;
// 	}

// 	for (int i = idx; i <n; i++) {

// 		arr.push_back(i+1);

// 		p(i+1,depth + 1);

// 		arr.pop_back();

// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	std::cout.tie(NULL);
// 	cin >> n >> m;
// 	p(0,0);
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<int> arr;
vector<bool> visited;
void Recursion(int k)
{
	if (arr.size() == m)
	{
		for (auto i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
		return;
	}

	for (int i = k; i <= n; i++)
	{
		if (!visited[i])
		{
			arr.push_back(i);
			visited[i] = true;
			Recursion(i + 1);
			visited[i] = false;
			arr.pop_back();
		}
	}
}
void Solve()
{
	cin >> n >> m;
	visited.resize(n + 1, false);
	Recursion(1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}