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
			if (i - stk.top() == 1) { // �ݴ°�ȣ�ε� top���ִ¼��� 1���̳���
				stk.pop();//pop�����ְ� �������������
				ans += stk.size();
			}
			else {
				stk.pop();//pop������� ���� �����ִ°����� ������ ����� �����ִ°��̱⶧���̴�
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