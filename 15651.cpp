// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;
// int n, m;
// vector<int> arr;
// const int MAX = 9;
// bool visited[MAX];

// void p(int depth) {
// 	if (depth == m) {
// 		for (int i = 0; i < arr.size(); i++) {
// 			cout << arr[i] << " ";
// 		}
// 		cout <<'\n';
// 		return;
// 	}

// 	for (int i = 1; i <= n; i++) {
// 		//if (visited[i] == true)continue;
// 		arr.push_back(i);
// 		visited[i] = true;

// 		p(depth + 1);

// 		arr.pop_back();
// 		visited[i] = false;
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	std::cout.tie(NULL);
// 	cin >> n >> m;
// 	p(0);
// }

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<int> arr;
// void Recursion()
// {
// 	if (arr.size() == m)
// 	{
// 		for (auto i : arr)
// 		{
// 			cout << i << " ";
// 		}
// 		cout << endl;
// 		return;
// 	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		arr.push_back(i);
// 		Recursion();
// 		arr.pop_back();
// 	}
// }
// void Solve()
// {
// 	cin >> n >> m;
// 	Recursion();
// }
// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	Solve();
// 	return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i + 1;

	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n; i++)
			v.push_back(v[i]);
	sort(v.begin(), v.end());

	do
	{
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << endl;
		reverse(v.begin() + m, v.end());
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}
//중복순열