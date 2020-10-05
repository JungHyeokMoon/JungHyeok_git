// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// #include <set>
// using namespace std;

// int r, c;

// const int MAX = 20;
// char alpha[MAX][MAX];
// bool visited[MAX][MAX];
// bool used[26];

// int dy[4] = { -1,1,0,0 };
// int dx[4] = { 0,0,-1,1 };

// int ret;
// void dfs(int y, int x, int dist) {
// 	ret = max(ret, dist);
// 	visited[y][x] = true;
// 	used[alpha[y][x] - 'A'] = true;
// 	for (int i = 0; i < 4; i++) {
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];
// 		if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
// 		//if (visited[ny][nx])continue;
// 		if (!used[alpha[ny][nx] - 'A'])dfs(ny, nx, dist + 1);
// 		//dfs(ny, nx, dist + 1);
// 	}
// 	visited[y][x] = false;
// 	used[alpha[y][x] - 'A'] = false;//이거돌려줘야함
// }


// int main() {
// 	//ios::sync_with_stdio(false);
// 	//cin.tie(NULL);
// 	//cout.tie(NULL);

// 	cin >> r >> c;

// 	for (int i = 0; i < r; i++) {
// 		getchar();
// 		for (int j = 0; j < c; j++) 
// 			alpha[i][j] = getchar();
// 	}
// 	dfs(0, 0, 1);
// 	cout << ret << "\n";


// 	return 0;
// }

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<bool> number;
int t;
void Init(){
	number.resize(10000,true);
	for(int i=2; i*i<=10000; i++){
		if(number[i]==true){
			for(int j=i+i; j<=10000; j=j+i){
				number[j]=false;
			}
		}
	}
}
int tenPow(int i){
	if(i==0)return 1;
	else if(i==1) return 10;
	else if(i==2) return 100;
	else return 1000;
}
bool IsInside(int num){
	if(1000<=num && num<=9999)
		return true;
	return false;
}
void bfs(int start, int destination,vector<int> & dist){
	queue<int> q;
	q.push(start);
	dist[start]=0;

	while(!q.empty()){
		int cur=q.front();
		q.pop();

		if(cur==destination)
			return ;

		vector<int> digit;
		int temp=cur;
		while(temp!=0){
			digit.push_back(temp%10);
			temp/=10;
		}

		for(int i=0; i<4; i++){
			for(int j=0; j<=9; j++){
				if(digit[i]==j) continue;
				int nextNumber=cur-digit[i]*tenPow(i)+tenPow(i)*j;
				if(!IsInside(nextNumber))continue;
				if(dist[nextNumber]!=-1)continue;
				if(number[nextNumber]==false)continue;
				q.push(nextNumber);
				dist[nextNumber]=dist[cur]+1;
			}
		}
	}
}
void Solve(){
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		vector<int> dist(10000,-1);
		bfs(a,b,dist);
		if(dist[b]!=-1)cout<<dist[b]<<endl;
		else cout<<"Impossible"<<endl;
	}
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