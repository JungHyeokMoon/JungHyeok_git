#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void josephus(int n, int k) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() > 2) {
		q.pop();
		for (int i = 0; i < k-1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
			
		}
	}
	
	vector<int> answer;
	answer.push_back(q.front());
	answer.push_back(q.back());
	sort(answer.begin(), answer.end());
	cout << answer.front() << " " << answer.back() << endl;
}
int C, N, K;
int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> K;
		josephus(N, K);
	}

	return 0;
}