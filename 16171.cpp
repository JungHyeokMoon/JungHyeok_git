#include <iostream>
#include <string>
using namespace std;
int answer(string s, string k) {
	string check = "";
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
			check += s[i];
		}
	}
	int n1 = k.length();
	for (int i = 0; i < n1; i++) {
		if (check[i] != k[i]) {
			//cout << "틀린답 출력" << check << endl;
			return 0;
		}
	}
	//cout << "맞은 답 출력" << check << endl;
	return 1;
}
int main() {
	string s, k;
	cin >> s >> k;
	cout << answer(s, k);

	return 0;
}