#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

vector<string >v;
int n;
class input {
public:
	string str;
	input(string s):str(s){}
};

bool compare(input s1, input s2) {
	if (s1.str.length() == s2.str.length()) {
		return s1.str < s2.str;
	}
	else {
		return s1.str.length() < s2.str.length();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);

	string prev = "";
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << v[i] << "\n";
			prev = v[i];
			continue;
		}

		if (v[i] == prev) {
			continue;
		}
		else {
			cout << v[i] << "\n";
			prev = v[i];
		}

	}
	
	return 0;
}