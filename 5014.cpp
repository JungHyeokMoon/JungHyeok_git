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

const int MAX = 1000000;
bool visited[MAX + 1];
int f, s, g, u, d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> f >> s >> g >> u >> d; //총 f층, 가려는곳 g층, 현재 있는층 s층,u버튼은 위로 u층 ,d버튼은 아래로 d층

	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	int ret = 0;
	visited[s] = true;
	bool flag = false;

	if (s == g) {
		cout << 0 << "\n";
		return 0;
	}
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();

		int uf = here + u;
		int df = here - d;
		if (uf == g||df==g) {
			ret = cnt + 1;
			flag = true;
			break;
		}
		
		if (1 <= uf && uf <= f) {
			if (!visited[uf]) {
				q.push(make_pair(uf, cnt + 1));
				visited[uf] = true;
			}
		}
		
		if (1 <= df && df <= f) {
			if (!visited[df]) {
				q.push(make_pair(df, cnt + 1));
				visited[df] = true;
			}
		}
		
	}
	if (flag) {
		cout << ret << "\n";
	}
	else {
		cout << "use the stairs" << "\n";
	}



	return 0;
}