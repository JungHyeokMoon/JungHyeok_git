// #include <bits/stdc++.h>
// using namespace std;
// int n, m; //세로 n 가로 m
// int tetromino[500][500];
// bool visited[500][500];
// int ret = -987654321;
// bool isinside(int y, int x)
// {
//     if (y >= 0 && y < n && x >= 0 && x < m)
//     {
//         return true;
//     }
//     return false;
// }
// int dy[4]={-1,0,1,0};
// int dx[4]={0,1,0,-1};
// void Input()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> tetromino[i][j];
//         }
//     }
// }
// void dfs(int y, int x, int cnt,int sum){
//     if(cnt==4){
//         ret=max(ret,sum);
//         return ;
//     }

//     visited[y][x]=true;
//     for(int i=0; i<4; i++){
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         if(!isinside(ny,nx))continue;
//         if(visited[ny][nx])continue;
//         dfs(ny,nx,cnt+1,sum+tetromino[y][x]);
//     }
//     visited[y][x]=false;

// }
// void find(int y, int x){
//     int Min=987654321;
//     int cnt=1;
//     int sum=tetromino[y][x];
//     for(int i=0; i<4; i++){
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         if(!isinside(ny,nx))continue;
//         cnt++;
//         Min=min(Min,tetromino[ny][nx]);
//         sum+=tetromino[ny][nx];
//     }
//     if(cnt==5){
//         sum-=Min;

//     }
//     ret=max(ret,sum);
//     return ;
// }
// void Solve()
// {
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<m ; j++){
//             dfs(i,j,0,0);
//             find(i,j);
//         }
//     }
//     cout<<ret<<"\n";
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     Input();
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<vector<int>> MAP;
vector<vector<bool>> visited;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
int ret=-1e9;
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<int>(m));
    visited.resize(n,vector<bool>(m,false));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>MAP[i][j];
            
} 
bool isInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m)
        return true;
    return false;
}
void dfs(int y, int x ,int cnt, int sum){
    if(cnt==3){
        ret=max(ret,sum);
        return ;
    }
    visited[y][x]=true;
    for(int i=0; i<4; i++){
        int ny=y+dir[i].first;
        int nx=x+dir[i].second;
        if(!isInside(ny,nx))continue;
        if(visited[ny][nx])continue;
        dfs(ny,nx,cnt+1,sum+MAP[ny][nx]);
    }
    visited[y][x]=false;
}
void ExShape(int y, int x){
    int temp=-1e9;
    //ㅗ
    if(x-1>=0 && x+1<m && y>=0 &&y+1<n)
        ret=max(ret,MAP[y][x]+MAP[y+1][x]+MAP[y+1][x-1]+MAP[y+1][x+1]);
    //ㅏ
    if(y>=0 && y+2<n &&x>=0 &&x+1<m)
        ret=max(ret,MAP[y][x]+MAP[y+1][x]+MAP[y+2][x]+MAP[y+1][x+1]);
    //ㅓ
    if(y>=0 && y+2<n &&x-1>=0 && x<m)
        ret=max(ret,MAP[y][x]+MAP[y+1][x]+MAP[y+2][x]+MAP[y+1][x-1]);
    //ㅜ
    if(y>=0 && y+1<n && x>=0 && x+2<m)
        ret=max(ret,MAP[y][x]+MAP[y][x+1]+MAP[y][x+2]+MAP[y+1][x+1]);
}
void Solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dfs(i,j,0,MAP[i][j]);
            ExShape(i,j);
        }
    }
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