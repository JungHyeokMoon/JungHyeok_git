#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int garo, sero;
//int ret = 0;
const int MAX = 51;
bool visited[MAX][MAX];
char arr[MAX][MAX];

int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool isinside(int hx, int hy) {
	if (hx >= 0 && hy >= 0 && hx < garo && hy < sero)
		return true;

	return false;
}

int bfs(int hx, int hy,int cnt) {
	
	queue<pair<int,pair<int, int>>> q;
	int ret = -1;


	q.push(make_pair(cnt,make_pair(hx, hy)));
	while (!q.empty()) {
		int hx = q.front().second.first;
		int hy = q.front().second.second;
		int cnt = q.front().first;
		
		q.pop();
	
		for (int i = 0; i < 4; i++) {
			int nx = hx + dir[i][0];
			int ny = hy + dir[i][1];
			
			if (nx < 0 || ny < 0 || nx >= garo || ny >= sero || visited[nx][ny])continue;
			if (arr[nx][ny] == 'W')continue;
			q.push(make_pair(cnt + 1, make_pair(nx, ny)));
			visited[nx][ny] = true;
		}
		ret = cnt;

	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(NULL);

	cin >> garo >> sero;
	for (int i = 0; i < garo; i++) {
		for (int j = 0; j < sero; j++) {
			cin >> arr[i][j];
		}
	}
	
	int ans = -1;
	
	for (int i = 0; i < garo; i++) {
		for (int j = 0; j < sero; j++) {
			if (arr[i][j] == 'L') {
				ans = max(ans, bfs(i, j,0));
				memset(visited, false, sizeof(visited));
				
			}
		}
	}
	
	cout << ans << endl;
}