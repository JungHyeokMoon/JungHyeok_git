#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int alphabet[26];

int main() {
	string s;
	int len;
	while (cin >> s) {
		len = s.size();
		for (int i = 0; i < len; ++i) {
			if ('a' <= s[i] && s[i] <= 'z')
				alphabet[s[i] - 'a']++;
		}
	}
	
	int ans = alphabet[0];

	for (int i = 1; i < 26; ++i) {
		ans = max(ans, alphabet[i]);
	}//제일많은개수찾고
	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] == ans)
			cout << (char)(i + 'a');
	}
	cout << "\n";
	return 0;
}