#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
using namespace std;
int n;
const int MAX = 1000000;
long long answer[MAX + 1];
queue<long long > q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	answer[0] = 0;
	for (int i = 1; i <= 9; i++) {
		q.push(i);
		answer[i] = i;
	}
	
	int idx = 9;
	while (idx <= n) {
		if (q.empty())
			break;

		long long descendingnum = q.front();
		q.pop();
		int lastnumber = descendingnum % 10;
		for (int i = 0; i < lastnumber; i++) {
			q.push(descendingnum * 10 + i);
			answer[++idx] = descendingnum * 10 + i;
		}
	}

	if (answer[n] == 0 && n) {
		cout << -1 << "\n";
	}
	else {
		cout << answer[n] << "\n";
	}


	
	return 0;
}