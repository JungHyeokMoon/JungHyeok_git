#include <iostream>
#include <string>
using namespace std;

string rot13(string s) {
	for (int i = 0; i < s.size(); i++) {
		if ('a' <= s[i] && s[i] <= 'm')
			s[i] = s[i] + 13;
		else if ('n' <= s[i] && s[i] <= 'z')
			s[i] = s[i] - 13;
		else if ('A' <= s[i] && s[i] <= 'M')
			s[i] = s[i] + 13;
		else if ('N' <= s[i] && s[i] <= 'Z')
			s[i] = s[i] - 13;
	}
	return s;
}

int main(){
	string s;
	getline(cin, s);
	cout << rot13(s) << endl;

	return 0;

}