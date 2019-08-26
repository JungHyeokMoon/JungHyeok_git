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

const int MAX = 1000;
int tomato[MAX + 1][MAX + 1];
int m, n;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	queue <pair<int,int>> q;
	cin >> m >>n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	

	while (!q.empty()) {
		int hy = q.front().first;
		int hx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = hx+dx[i];
			int ny = hy + dy[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (!tomato[ny][nx]) {
				tomato[ny][nx] = tomato[hy][hx] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	
	int ret = -987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0){
				cout << -1 << "\n";
				return 0;
			}
			ret = max(ret, tomato[i][j]);
		}
	}

	cout << ret - 1 << "\n";

	return 0;

}