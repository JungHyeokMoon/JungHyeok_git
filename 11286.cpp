#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;
int n;
class input {
public:
	int num;
	input(int n):num(n){}
};

bool operator<(const input& a, const input& b) {
	int absa = abs(a.num);
	int absb = abs(b.num);
	if (absa == absb) {
		return a.num > b.num;
	}
	else {
		return absa > absb;
	}
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<input> pq;


	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num != 0) {
			pq.push(num);
		}
		else {
			if (!pq.size()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top().num << "\n";
				pq.pop();
			}
		}
	}
	

	


	return 0;
}