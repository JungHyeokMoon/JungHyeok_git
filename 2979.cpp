#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int a, b, c;
int n;
struct time {
	int arrival;
	int leave;
};
int ret = 0;
vector<int> arr(101, 0);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> c;
	
	time t;
	for (int i = 0; i < 3; i++) {
		cin >> t.arrival >> t.leave;
		for (int j = t.arrival; j < t.leave; j++) {
			++arr[j];
		}
		n = max(t.leave, n);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1)ret += a;
		else if (arr[i] == 2)ret += (b * 2);
		else if(arr[i]==3) ret += (c * 3);
	}
	cout << ret << endl;
	return 0;
	
}
