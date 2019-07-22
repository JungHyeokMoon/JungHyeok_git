#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>>pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			//cout << "출력 : ";
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(num);
	}
}
//연속된 정수값찾을때 해결방법