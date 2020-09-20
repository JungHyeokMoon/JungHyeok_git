#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m;
vector<vector<int>> MAP;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};   
void Init()
{
    cin >> n >> m;
    MAP.resize(n, vector<int>(m));
    for(auto & i :MAP)
        for(auto & j :i)
            cin>>j;
}

bool IsInside(int y, int x){
    if(y>=0 && y< n && x>=0 &&x<m)
        return true;
    return false;
}
bool BoundaryCheck(int y, int x){
    int cnt=0;
    for(int i=0 ;i<4; i++){
        int ny=y+dir[i].first;
        int nx=x+dir[i].second;

        if(!IsInside(ny,nx))continue;
        if(MAP[ny][nx]==0)cnt++;
    }
    return cnt<2? false:true;
}
void bfs(){
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=true;

    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;
            if(!IsInside(ny,nx))continue;
            if(visited[ny][nx])continue;
            if(MAP[ny][nx]>=1){
                MAP[ny][nx]+=1;
                continue;
            }
            q.push({ny,nx});
            visited[ny][nx]=true;
        }
    }
}
bool Melt(){
    bool flag=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(MAP[i][j]>=3){
                MAP[i][j]=0;
                flag=true;
            }
            else if(MAP[i][j]==2)
                MAP[i][j]=1;
        }
    }
    return flag;
}
void Solve(){
    int Time=0;
    while(1){
        bfs();
        if(Melt()) Time++;
        else break;
    }
    cout<<Time<<endl;
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

