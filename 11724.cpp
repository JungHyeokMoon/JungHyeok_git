#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
#include <cstring> //memset함수
using namespace std;

vector<int> a[1000+1];
int check[1000 + 1];

void dfs(int x) {
	check[x] = true;
	//printf("%d ", x);
	for (unsigned int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false)
			dfs(y);
	}
}

void bfs(int x) {
	queue<int> q;
	memset(check, false, sizeof(check)); //dfs를 하고난 이후에 check 배열이 달라져있으므로 해놔야한다
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		printf("%d ", x);
		for (unsigned int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}

}

int main() {
	int n, m;
	int component = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int to, end;
		scanf("%d %d", &to, &end);
		a[to].push_back(end);
		a[end].push_back(to);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}//이거 해줘야함 정점번호가 1부터이고 정렬해줘야 번호가작은순서부터 들어가므로


	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			component += 1;
		}
		
	}//모든정점에 대해 정점을 방문하지 않았으면 dfs를하고 답을+1해줌, dfs나 bfs는 모든 정점을 한번씩 탐색하기때문이다.

	printf("%d\n", component);
	return 0;

}

