#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == 'Z') {
				s[i] = 'A';
			}
			else {
				s[i]++;
			}
		}
		cout << "String #" << i << endl;
		cout << s << endl;
		cout << endl;

	}
	return 0;
}
