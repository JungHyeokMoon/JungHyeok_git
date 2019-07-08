#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool isinside(int x,int y){
	return (x >= 0 && x <n) && (y < m &&y >=0);
}
int  ret;
void bfs(int x, int y,int cnt) {
	
	queue<pair<pair<int, int>, int>> q;
	visited[x][y] = true;
	q.push(make_pair(make_pair(x, y), cnt));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			ret = max(ret, cnt);
		} //탈출조건
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (visited[next_x][next_y] == false && isinside(next_x, next_y) == true && arr[next_x][next_y] == 1) {

				q.push(make_pair(make_pair(next_x, next_y), cnt + 1));
				visited[next_x][next_y] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs(0, 0,1);
	cout << ret << endl;
	return 0;
}
