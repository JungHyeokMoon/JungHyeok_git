#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int C;
string str;
string solve() {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
			s.push(str[i]);
		}
		else {
			if (s.empty()) {
				return "NO";
			}
			if (str[i] == ']') {
				if (s.top() == '[') {
					s.pop();
				}
				else {
					return "NO";
				}
			}
			else if (str[i] == '}') {
				if (s.top() == '{') {
					s.pop();
				}
				else {
					return "NO";
				}
			}
			else if (str[i] == ')') {
				if (s.top() == '(') {
					s.pop();
				}
				else {
					return "NO";
				}
			}
		}
	}
	if (s.empty()) {
		return "YES";
	}
	else {
		return "NO";
	}
}
int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> str;
		cout << solve() << endl;
	}
	
	

	return 0;
}
