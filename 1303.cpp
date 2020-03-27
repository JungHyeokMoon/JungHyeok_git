#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
char Map[100][100];
bool visited[100][100]={false};
int n,m; //가로크기 n ,세로크기 m
int alias;
int enemy;
typedef pair<int,int> pii;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
bool isinside(int y,int x){
    if(y>=0 && y<m && x>=0 &&x<n){
        return true;
    }
    return false;
}
void Input(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<n; j++){
            Map[i][j]=temp[j];
        }
    }

}
int bfs(int y, int x , char ch){
    visited[y][x]=true;
    queue<pii> q;
    q.push({y,x});
    int temp=0;
    
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        q.pop();
        temp++;

        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(visited[ny][nx])continue;
            if(Map[ny][nx]!=ch)continue;
            visited[ny][nx]=true;
            q.push({ny,nx});
        }
    }

    return pow(temp,2);
}
void Solve(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                if(Map[i][j]=='W'){
                    alias+=bfs(i,j,'W');
                }else{
                    enemy+=bfs(i,j,'B');
                }
            }
        }
    }
    cout<<alias<<" "<<enemy<<endl;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}