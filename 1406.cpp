#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

char a[600000];
int main(){
	stack<char> stk1;
	stack<char> stk2;

	scanf("%s", a);
	int n = strlen(a);
	
	for (int i = 0; i < n; i++) {
		stk1.push(a[i]);
	}

	
	int m;
	scanf("%d", &m); // 반복할 명령 입력
	
	
	while(m--){
		char command;
		scanf(" %c", &command);
		if (command == 'L') {
			if (!stk1.empty()) {//stk1이 비어있지않을경우 즉 커서가 맨앞에있는경우가아니라면
				stk2.push(stk1.top());
				stk1.pop();
			}
		}	else if (command == 'D') {
			if (!stk2.empty()) {
				stk1.push(stk2.top());
				stk2.pop();
			}
		}	else if (command == 'B') {
			if (!stk1.empty()) {
				stk1.pop();
			}
		}	else if (command == 'P') {
			char c;
			scanf(" %c", &c);
			stk1.push(c);
		}
	}

	while (!stk1.empty()) {
		stk2.push(stk1.top());
		stk1.pop();
	}

	while (!stk2.empty()) {
		printf("%c", stk2.top());
		stk2.pop();
	}
	cout << endl;
	return 0;
}