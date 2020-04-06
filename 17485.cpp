#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;
vector<vector<int>> path;
int dp[1000][1000][3];
int result=1e9;
void Input(){
    cin>>n>>m;
    path.resize(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for (int j = 0; j < m; j++)
        {
            cin>>path[i][j];
        }
    }
    
}
const int dy[3]={1,1,1};
const int dx[3]={-1,0,1};
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m ){
        return true;
    }
    return false;
}
int Travel(int y, int x, int direc){
    int &ret=dp[y][x][direc];
    if(ret!=-1){
        return ret;
    }
    if(y==n-1){
        return ret=path[y][x];
    }
    ret=1e9;
    for(int i=0; i<3; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(i==direc)continue;
        if(!isinside(ny,nx))continue;
        ret=min(ret,Travel(ny,nx,i));
    }
    return ret+=path[y][x];
}
void Solve(){
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++){
            result=min(result,Travel(0,i,j));
        }
    }
    cout<<result<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}