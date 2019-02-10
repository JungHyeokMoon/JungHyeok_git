#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	queue<int> q;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		q.push(i);

	printf("<");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		if (i != n - 1) {
			printf("%d, ", q.front());
			q.pop();
		}
		else {
			printf("%d", q.front());
			q.pop();
		}

	}

	
	printf(">\n");

	return 0;
}