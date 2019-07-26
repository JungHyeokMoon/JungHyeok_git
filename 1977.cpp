#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
bool visited[10001];
int sum = 0;
vector<int>v;
void solve(int n,int m) {
	bool ok = false;
	for (int i = n; i <= m; i++) {
		if (visited[i]) {
			ok = true;
			v.push_back(i);
			sum += i;
		}
	}

	if (!ok) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << v.front() << endl;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= 100; i++) {
		visited[i*i] = true;
	}
	solve(n, m);
	return 0;
}


