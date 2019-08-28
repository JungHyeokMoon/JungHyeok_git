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

int r, c;

const int MAX = 20;
char alpha[MAX][MAX];
bool visited[MAX][MAX];
bool used[26];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int ret;
void dfs(int y, int x, int dist) {
	ret = max(ret, dist);
	visited[y][x] = true;
	used[alpha[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
		//if (visited[ny][nx])continue;
		if (!used[alpha[ny][nx] - 'A'])dfs(ny, nx, dist + 1);
		//dfs(ny, nx, dist + 1);
	}
	visited[y][x] = false;
	used[alpha[y][x] - 'A'] = false;//이거돌려줘야함
}


int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) 
			alpha[i][j] = getchar();
	}
	dfs(0, 0, 1);
	cout << ret << "\n";


	return 0;
}