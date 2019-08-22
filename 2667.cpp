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

const int MAX = 25;
int arr[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n;
vector<int> answer;
int cnt = 0;

void dfs(int y, int x) {


	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (arr[ny][nx]==0)continue;
		if (visited[ny][nx])continue;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
		cnt++;
		visited[ny][nx] = true;
		dfs(ny, nx);
	}

}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j]) {
				visited[i][j] = true;
				cnt = 1;
				dfs(i, j);
				answer.push_back(cnt);
			}
		}
	}


	sort(answer.begin(), answer.end());
	int len = answer.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		cout << answer[i] << "\n";
	}
	
	return 0;
}