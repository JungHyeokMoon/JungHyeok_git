#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<vector<char>> MAP;
vector<vector<bool>> isvisited;
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}
typedef pair<int,pair<int,int>> piii;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
int ret=-987654321;
void Input(){
	cin>>n>>m;
	MAP.resize(n);
	isvisited.resize(n);
	for(int i=0; i<n; i++){
		MAP[i].resize(m);
		isvisited[i].resize(m,false);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m ; j++){
			cin>>MAP[i][j];
		}
	}
}
int bfs(int y, int x){
	for(int i=0; i<n; i++){
		fill(isvisited[i].begin(),isvisited[i].begin()+m,false);
	}

	isvisited[y][x]=true;
	queue<piii> q;
	q.push({{0},{y,x}});
	int temp=-987654321;

	while(!q.empty()){
		int hy=q.front().second.first;
		int hx=q.front().second.second;
		int hd=q.front().first;
		q.pop();
		// cout<<"hy : "<<hy<<" , hx : "<<hx<<" , hd : "<<hd<<endl;
		if(hd!=0){
			temp=max(temp,hd);
		}
		for(int i=0; i<4; i++){
			int ny=hy+dy[i];
			int nx=hx+dx[i];
			if(!isinside(ny,nx))continue;
			if(isvisited[ny][nx])continue;
			if(MAP[ny][nx]=='L'){
				isvisited[ny][nx]=true;
				q.push({{hd+1},{ny,nx}});
			}
		}
	}
	
	return temp;
}
void Solve(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(MAP[i][j]=='L'){
				// cout<<"i : "<<i<<" , j : "<<j<<endl;
				ret=max(ret,bfs(i,j));//지상인곳을 다 bfs돌려서 
			}
		}
	}
	cout<<ret<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	Input();
	Solve();
	return 0;
}