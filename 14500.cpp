#include <bits/stdc++.h>
using namespace std;
int n, m; //세로 n 가로 m
int tetromino[500][500];
bool visited[500][500];
int ret = -987654321;
bool isinside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < m)
    {
        return true;
    }
    return false;
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tetromino[i][j];
        }
    }
}
void dfs(int y, int x, int cnt,int sum){
    if(cnt==4){
        ret=max(ret,sum);
        return ;
    }
    
    visited[y][x]=true;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isinside(ny,nx))continue;
        if(visited[ny][nx])continue; 
        dfs(ny,nx,cnt+1,sum+tetromino[y][x]);
    }
    visited[y][x]=false;
    
}
void find(int y, int x){
    int Min=987654321;
    int cnt=1;
    int sum=tetromino[y][x];
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isinside(ny,nx))continue;
        cnt++;
        Min=min(Min,tetromino[ny][nx]);
        sum+=tetromino[ny][nx];
    }
    if(cnt==5){
        sum-=Min;
        
    }
    ret=max(ret,sum);
    return ;
}
void Solve()
{
    for(int i=0; i<n ; i++){
        for(int j=0; j<m ; j++){
            dfs(i,j,0,0);
            find(i,j);
        }
    }   
    cout<<ret<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}