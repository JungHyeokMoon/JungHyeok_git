// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// #include <stack>
// using namespace std;

// int n, m;
// const int MAX = 100;
// int dist[MAX + 1][MAX + 1];
// const int INF= 1000000000;
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			dist[i][j] = i == j ? 0 : INF;
// 		}
// 	}
// 	for (int i = 0; i < m; i++) {
// 		int a, b, c;
// 		cin >> a >> b >> c;
// 		dist[a-1][b-1] = min(dist[a-1][b-1], c);
// 	}

// 	for (int k = 0; k < n; k++) {
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
// 			}
// 		}
// 	}

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (dist[i][j] == INF)
// 				dist[i][j] = 0;
// 			printf("%d ", dist[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<int>> dist;
const int INF=1000000000;
void Init(){
	cin>>n>>m;
	dist.resize(n+1,vector<int>(n+1));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			dist[i][j]= (i==j) ? 0: INF;

	for(int i=0; i<m; i++){
		int start, destination, cost;
		cin>>start>>destination>>cost;
		dist[start][destination]=min(dist[start][destination],cost);
	}
}
void Print(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dist[i][j]==INF)cout<<0<<" ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
		
}
void Solve(){
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

	Print();
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