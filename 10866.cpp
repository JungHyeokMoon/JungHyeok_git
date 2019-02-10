#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string s;
	int num;
	deque<int> deq;
	while (n--) {
		cin >> s;
		if (s == "push_front") {
			scanf("%d", &num);
			deq.push_front(num);
		}
		else if (s == "push_back") {
			scanf("%d", &num);
			deq.push_back(num);
		}
		else if (s == "pop_front") {
			if (deq.empty())
				printf("-1\n");
			else {
				printf("%d\n", deq.front());
				deq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (deq.empty())
				printf("-1\n");
			else {
				printf("%d\n", deq.back());
				deq.pop_back();
			}
		}
		else if (s == "size") {
			printf("%d\n", deq.size());
		}
		else if (s == "empty") {
			if (deq.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (s == "front") {
			if (deq.empty()) {
				printf("-1\n");
			}
			else
				printf("%d\n", deq.front());
		}
		else if (s == "back") {
			if (deq.empty()) {
				printf("-1\n");
			}
			else
				printf("%d\n", deq.back());
		}
	}

	return 0;
}