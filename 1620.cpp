#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;
const int MAX = 100000;
int n, m;
string arr[MAX + 1];

map<string, int> M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		M.insert(pair<string , int>(str,i));
		arr[i]=str;
	}
	
	string s;
	for (int j = 0; j < m; j++) {
		cin >> s;
		if ('0' <= s[0] &&   s[0]<='9') {
			int search = stoi(s);
			cout << arr[search] << "\n";
		}
		else {
			map<string, int>::iterator it = M.find(s);
			cout << it->second << "\n";
		}

		/*int temp = s[0] - '0';
		if (17 <= temp && temp <= 42) {
			map<string, int>::iterator it = M.find(s);
			cout <<it->second << "\n";
		}//문자열인경우
		else {
			int search = stoi(s);
			for (auto p = M.begin(); p != M.end(); p++) {
				if (p->second == search) {
					cout<< p->first << "\n";
					break;
				}
			}
		}*/
	}
	
	return 0;
}	