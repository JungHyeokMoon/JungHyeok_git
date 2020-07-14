// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// using namespace std;

// int l, c;
// char input[15];
// char ret[16];
// bool isvowel[26];

// void password(int pos, int prev, int consonant,int vowel) {
// 	if (pos == l) {
// 		if (consonant >= 2 && vowel >= 1) {
// 			for (int i = 0; i < l; i++) {
// 				cout << ret[i];
// 			}
// 			cout << "\n";
// 			return ;
// 		}
// 	}

// 	for (int i = prev + 1; i < c; i++) {
// 		ret[pos] = input[i];
// 		password(pos + 1, i, consonant + !isvowel[input[i] - 'a'], vowel + isvowel[input[i] - 'a']);
// 	}
// }
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> l >> c;
// 	for (int i = 0; i < c; i++)
// 		cin >> input[i];
// 	sort(input, input + c);
// 	isvowel[0] = isvowel[4] = isvowel[8] = isvowel[14] = isvowel[20] = true;
// 	password(0, -1, 0, 0);

// 	return 0;
// }
// //블로그참고해서풀었음 , 모음 처리하는방법과 백트랙킹

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int l, c;
vector<char> arr;
vector<char> ret;
void Init()
{
	cin >> l >> c;
	arr.resize(c);
	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
}

void Recursion(int k, int vowel, int constant)
{
	if (ret.size() == l)
	{
		if (vowel >= 1 && constant >= 2)
		{
			for (char c : ret)
			{
				cout << c;
			}
			cout << endl;
		}
		return;
	}
	for (int i = k; i < c; i++)
	{
		ret.push_back(arr[i]);
		if (arr[i] - 'a' == 0 || arr[i] - 'a' == 4 || arr[i] - 'a' == 8 || arr[i] - 'a' == 14 || arr[i] - 'a' == 20)
		{
			Recursion(i + 1, vowel + 1, constant);
		}
		else
		{
			Recursion(i + 1, vowel, constant + 1);
		}
		// Recursion(i + 1);
		ret.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();
	Recursion(0, 0, 0);
	return 0;
}