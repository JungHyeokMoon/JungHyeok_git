#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 300;

bool isinside(int x, int y,int l) {
	return (x >= 0 && x < l) && (y >= 0 && y < l);
}
int t;
int l;
int hx, hy;
int dx, dy;

struct x_y {
	int x, y;
};
x_y arr[8] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l >> hx >> hy >> dx >> dy;
		queue<pair<int, pair<int, int>>> q;
		bool visited[300][300] = { false };
		q.push(make_pair(0, make_pair(hx, hy)));
		visited[hx][hy] = true;
		while (!q.empty()) {
			int cnt = q.front().first;
			int hx = q.front().second.first;
			int hy = q.front().second.second;
			q.pop();
			if (hx == dx && hy == dy) {
				cout << cnt << endl;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = hx + arr[i].x;
				int ny = hy + arr[i].y;
				if (isinside(nx, ny, l) && visited[nx][ny]==false) {
					visited[nx][ny] = true;
					q.push(make_pair(cnt + 1, make_pair(nx, ny)));
				}

			}
		}
	}
	return 0;
}



