#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int C, N;
vector<int> h;
int solve() {
	h.push_back(0);
	stack<int> remaining;
	int ret = 0;
	int width;
	for (int i = 0; i < h.size(); i++) {
		while (!remaining.empty() && h[remaining.top()]>=h[i]) {
			int j = remaining.top();
			remaining.pop();
			width = -1;
			if (remaining.empty()) {
				width = i;
			}
			else {
				width = (i - remaining.top() - 1);
			}
			ret = max(ret, h[j]*width);
		}
		remaining.push(i);
	}
	return ret;

}
int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N;
		h = vector<int>(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> h[i];
		}
		cout << solve() << endl;
	}
	return 0;
}