#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n;
queue <int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	while (!q.empty()) {
		if (q.size() != 1) {
			int a = q.front();
			cout << a << " ";
			q.pop();
			int b = q.front();
			q.pop();
			q.push(b);
		}
		else
			break;
	}
	cout << q.front() << endl; 
	return 0;
	
}
