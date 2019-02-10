#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string s;
	int num;
	queue<int> q;
	while (n--) {
		cin >> s;
		if (s == "push") {
			scanf("%d", &num);
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (s == "size") {
			printf("%d\n", q.size());
		}
		else if (s == "empty") {
			if (q.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (s == "front") {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if (s == "back") {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());	
		}
	}

	return 0;
}