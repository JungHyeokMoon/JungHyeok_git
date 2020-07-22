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
// 		if (visited[i] == true)continue;
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
// vector<bool> visited;
// vector<int> arr;
// void Recursion()
// {
// 	if (arr.size() == m)
// 	{
// 		for (int i = 0; i < arr.size(); i++)
// 		{
// 			cout << arr[i] << " ";
// 		}
// 		cout << endl;
// 		return;
// 	}

// 	for (int i = 1; i <= n; i++)
// 	{
// 		if (!visited[i])
// 		{
// 			visited[i] = true;
// 			arr.push_back(i);
// 			Recursion();
// 			arr.pop_back();
// 			visited[i] = false;
// 		}
// 	}
// }
// void Solve()
// {
// 	cin >> n >> m;
// 	visited.resize(n + 1, false);
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

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<int> arr;
// set<string> s;
// void Init()
// {
// 	cin >> n >> m;
// 	arr.resize(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		arr[i] = i + 1;
// 	}
// }
// void Solve()
// {
// 	do
// 	{
// 		string str;
// 		for (int i = 0; i < m; i++)
// 		{
// 			str.push_back(arr[i] + '0');
// 			str.push_back(' ');
// 		}

// 		if (s.find(str) == s.end())
// 		{
// 			s.insert(str);
// 			cout << str << endl;
// 		}
// 	} while (next_permutation(arr.begin(), arr.end()));
// }
// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	Init();
// 	Solve();
// 	return 0;
// }

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<int> arr;
// // set<string> s;
// void Init()
// {
// 	cin >> n >> m;
// 	arr.resize(n, 1);
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (i < m)
// 			arr[i] = 0;
// 		else
// 		{
// 			arr[i] = i + 1;
// 		}
// 	}
// 	for (auto i : arr)
// 	{
// 		cout << i << " ";
// 	}
// }
// void Solve()
// {
// 	do
// 	{
// 		for (auto i : arr)
// 		{
// 			if (i != 0)
// 			{
// 				cout << i << " ";
// 			}
// 		}
// 		cout << endl;
// 	} while (next_permutation(arr.begin(), arr.end()));
// }
// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	Init();
// 	// Solve();
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
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }

    do
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << " ";
        cout << endl;
        reverse(v.begin() + m, v.end());
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
//순열