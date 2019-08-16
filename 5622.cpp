#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;

string str;
int sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<string, int>> v;
	v.push_back(make_pair("ABC", 3));
	v.push_back(make_pair("DEF", 4));
	v.push_back(make_pair("GHI", 5));
	v.push_back(make_pair("JKL", 6));
	v.push_back(make_pair("MNO", 7));
	v.push_back(make_pair("PQRS", 8));
	v.push_back(make_pair("TUV", 9));
	v.push_back(make_pair("WXYZ", 10));
	
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		bool flag = true;
		char temp1 = str[i];
		for (int j = 0; j < 8; j++) {
			string temp2 = v[j].first;
			for (int k = 0; k < temp2.size(); k++) {
				if (temp2[k] == temp1) {
					flag = false;
					sum += v[j].second;
					break;
				}
			}
			if (flag == false)
				break;
		}
	}

	cout << sum << endl;

	return 0;
}