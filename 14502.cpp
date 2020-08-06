// #pragma warning(disable:4996)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <stack>
// #include <string>
// #include <cmath>
// #include <queue>
// #include <cstdlib>
// #include <map>
// #include <deque>
// using namespace std;


// int n, m;
// const int MAX = 8;
// int input[MAX][MAX];
// int dy[4] = {-1,0,1,0};
// int dx[4] = {0,1,0,-1};
// int test[MAX][MAX];
// int ret = -987654321;

// void bfs() {
// 	queue<pair<int, int>> q;

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			test[i][j] = input[i][j];
// 			if (test[i][j] == 2) {
// 				q.push(make_pair(i, j));
// 			}

// 		}
// 	}



// 	while (!q.empty()) {
// 		int hy = q.front().first;
// 		int hx = q.front().second;

// 		q.pop();
// 		for (int i = 0; i < 4; i++) {
// 			int ny = hy + dy[i];
// 			int nx = hx + dx[i];
// 			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
// 				if (test[ny][nx] == 0) {
// 					test[ny][nx] = 2;
// 					q.push(make_pair(ny, nx));
// 				}
// 			}
// 		}
// 	}


// 	int cnt = 0;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (!test[i][j])cnt++;
// 		}
// 	}
// 	ret = max(ret, cnt);
// }





// void makewall(int cnt) {
// 	if (cnt == 3) {
// 		bfs();
// 		return;
// 	}

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (input[i][j] == 0) {
// 				input[i][j] = 1;
// 				makewall(cnt + 1);
// 				input[i][j] = 0;
// 			}
// 		}
// 	}
// }
// void setting() {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			test[i][j] = input[i][j];
// 		}
// 	}
// }
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> input[i][j];
// 		}
// 	}
// 	makewall(0);

// 	cout << ret << "\n";


// 	return 0;
// }	

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<vector<int>> MAP;
pair<int, int> dir[4]={ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int ret=-1e9;
vector<pair<int, int>>InitSafeArea;
vector<pair<int, int>> virus;
vector<bool> combi;
bool isInside(int y, int x) {
	if (y>=0 && y<n && x>=0 && x<m)
		return true;
	return false;
}
void Init() {
	cin>>n>>m;
	MAP.resize(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin>>MAP[i][j];
			if (MAP[i][j]==0)
				InitSafeArea.push_back({ i, j });
			else if (MAP[i][j]==2)
				virus.push_back({ i, j });
		}
	}
	combi.resize(InitSafeArea.size(), true);
	fill(combi.begin(), combi.begin()+3, false);
}
void Output(vector<vector<int>> &MAP) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout<<MAP[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int Cal(vector<vector<int>> &MAP) {
	int cnt=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (MAP[i][j]==0)cnt++;

	return cnt;
}
int bfs() {
	int length=combi.size();
	vector<vector<int>> C_MAP=MAP;
	for (int i=0; i<length; i++)
		if (combi[i]==false)
			C_MAP[InitSafeArea[i].first][InitSafeArea[i].second]=1;

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, int>> q;
	for (int i=0; i<virus.size(); i++) {
		q.push(virus[i]);
		visited[virus[i].first][virus[i].second]=true;
	}
	while (!q.empty()) {
		auto cur=q.front();
		int hy=cur.first;
		int hx=cur.second;
		q.pop();

		for (int i=0; i<4; i++) {
			int ny=hy+dir[i].first;
			int nx=hx+dir[i].second;
			if (!isInside(ny, nx))continue;
			if (visited[ny][nx])continue;
			if(C_MAP[ny][nx]==0){
				C_MAP[ny][nx]=2;
				q.push({ny,nx});
				visited[ny][nx]=true;
			}
		}
	}

	return Cal(C_MAP);
}


void Solve() {
	do {
		ret=max(ret, bfs());
	} while (next_permutation(combi.begin(), combi.end()));
	cout<<ret<<endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();
	Solve();
	return 0;
}