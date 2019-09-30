#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <map>
#include <deque>
using namespace std;


int n, m;
const int MAX = 8;
int input[MAX][MAX];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int test[MAX][MAX];
int ret = -987654321;

void bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			test[i][j] = input[i][j];
			if (test[i][j] == 2) {
				q.push(make_pair(i, j));
			}
			
		}
	}

	

	while (!q.empty()) {
		int hy = q.front().first;
		int hx = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
				if (test[ny][nx] == 0) {
					test[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}


	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!test[i][j])cnt++;
		}
	}
	ret = max(ret, cnt);
}





void makewall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (input[i][j] == 0) {
				input[i][j] = 1;
				makewall(cnt + 1);
				input[i][j] = 0;
			}
		}
	}
}
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			test[i][j] = input[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}
	makewall(0);

	cout << ret << "\n";
	
	
	return 0;
}	