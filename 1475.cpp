// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// #include <stack>
// #include <iomanip>
// #include <math.h>
// using namespace std;
// string str;
// int number[10];

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> str;

// 	fill(number, number + 10, 1);
// 	int ret = 1;
// 	int len = str.size();
// 	for (int i = 0; i < len; i++) {
// 		int temp = str[i] - '0';

// 		if (temp == 6 || temp == 9) {
// 			int six = 6;
// 			int nine = 9;
// 			if (!number[six] && !number[nine]) {
// 				ret++;
// 				for (int i = 0; i <= 9; i++) {
// 					number[i]++;
// 				}
// 			}
// 			else if (!number[six] && number[nine]) {
// 				number[nine]--;
// 				continue;
// 			}
// 			else if (number[six] && !number[nine]) {
// 				number[six]--;
// 				continue;
// 			}

// 		}
// 		else {
// 			if (!number[temp]) {
// 				ret++;
// 				for (int i = 0; i <= 9; i++) {
// 					number[i]++;
// 				}
// 			}

// 		}
// 		number[temp]--;
// 	}

// 	cout << ret << "\n";

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string input;
vector<int> arr;
void Input()
{
	cin >> input;
	arr.resize(10, 0);
}
void Solve()
{
	int MAX = -1e9;
	for (int i = 0; i < input.size(); i++)
	{
		int temp = input[i] - '0';
		if (temp == 9 || temp == 6)
		{
			if (arr[9] > arr[6])
			{
				temp = 6;
			}
			else
			{
				temp = 9;
			}
		}
		arr[temp]++;
		MAX = max(arr[temp], MAX);
	}
	cout << MAX << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solve();
	return 0;
}