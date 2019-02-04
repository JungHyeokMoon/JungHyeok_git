#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> stk;
	int n;
	string s;
	scanf("%d", &n);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			scanf("%d", &num);
			stk.push(num);
			//printf("%d\n", stk.top());
		}
		else if (s == "pop") {
			if (stk.empty())
				printf("-1\n");
			else {
				printf("%d\n", stk.top());
				stk.pop();
			}
		}
		else if (s == "size") {
			printf("%d\n", stk.size());
		}
		else if (s == "empty") {
			if (stk.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (s == "top") {
			if (stk.empty())
				printf("-1\n");
			else
				printf("%d\n", stk.top());

		}
	}

    

	return 0;
}