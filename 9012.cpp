#include <iostream>
#include <stack>
#include <string>
using namespace std;
string solution(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt += 1;
		}
		else {//´Ý´Â°ýÈ£ÀÇ°æ¿ì
			cnt -= 1;
			if (cnt < 0)
				return "NO";
		}
		
	}
	if (cnt == 0)
		return "YES";
	else
		return "NO";

}
int main() {
	stack<char> stk;
	int n;
	scanf("%d", &n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << solution(s) << endl;
		
	}

	return 0;
}