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
string name;
string in_out;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, bool>m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> in_out;
		if (in_out == "enter") {
			map<string, bool>::iterator it = m.find(name);
			if (it == m.end()) {
				m.insert(make_pair(name, true));
			}
			else {
				it->second = true;
			}
		}
		else {
			map<string, bool>::iterator it = m.find(name);
			it->second = false;	
		}

	}

	map<string, bool>::iterator it2;
	stack<string> stk;
	for (it2 = m.begin(); it2 != m.end(); it2++) {
		if (it2->second == true) {
			stk.push(it2->first);
		}
	}
	while (!stk.empty()) {
		cout << stk.top() << "\n";
		stk.pop();
	}




	
	return 0;
}	