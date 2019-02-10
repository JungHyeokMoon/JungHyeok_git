#include <iostream>
#include <stack>
#include <string>
using namespace std;
int solution(string s) {
	stack<int> stk;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else {
			if (i - stk.top() == 1) { // 닫는괄호인데 top에있는수랑 1차이날때
				stk.pop();//pop을해주고 답을더해줘야함
				ans += stk.size();
			}
			else {
				stk.pop();//pop해줘야함 답을 더해주는과정이 스택의 사이즈를 더해주는것이기때문이다
				ans += 1;
			}
		}
	}
	return ans;
}
int main() {
	string str;
	cin >> str;
	cout << solution(str) << endl;
	return 0;
}