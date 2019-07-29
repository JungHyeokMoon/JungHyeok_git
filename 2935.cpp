#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
string a, b;
char op;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> a >> op>>b;
	if (op == '*') {
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] - '0' == 0) {
				cnt++;
			}
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] - '0' == 0) {
				cnt++;
			}
		}
		string answer = "1";
		for (int i = 0; i < cnt; i++) {
			answer += "0";
		}
		cout << answer << endl;
	}
	else if (op == '+') {
		int len1 = a.size();
		int len2 = b.size();
		
		if (len1 == len2) {
			string answer = "2";
			int cnt = 0;
			for (int i = 0; i < len1; i++) {
				if (a[i] - '0' == 0) {
					cnt++;
				}
			}
			for (int i = 0; i < cnt; i++) {
				answer += "0";
			}
			cout << answer << endl;
		}
		else {
			int lenmax = max(len1, len2);
			int lenmin = min(len1, len2);
			string answer = "1";
			for (int i = 0; i < lenmax-1; i++) {
				if (i == lenmax - lenmin-1) {
					answer += "1";
				}
				else {
					answer += "0";
				}
			}
			cout << answer << endl;
		}
		

	}
	return 0;
}



