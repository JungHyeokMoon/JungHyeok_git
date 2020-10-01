#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<int>> MAP;
vector<vector<int>> dist;
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<int>(m));
    dist.resize(n,vector<int>(m,-1));
    // for(auto & i :MAP)
    //     for(auto & j :i)
    //         cin>>j;

    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<m; j++)
            MAP[i][j]=temp[j]-'0';
    }
    
    // for(auto i: MAP){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
}
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
bool IsInside(int y , int x){
    if(y>=0 && y<n && x>=0 &&x<m)
        return true;
    return false;
}
void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    dist[y][x]=0;

    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int hy=cur.first;
        int hx=cur.second;

        // cout<<hy<<" "<<hx<<" "<<dist[hy][hx]<<endl;
        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;
            if(!IsInside(ny,nx))continue;
            if(MAP[ny][nx]==1)continue;
            if(dist[ny][nx]!=-1)continue;

            q.push({ny,nx});
            dist[ny][nx]=dist[hy][hx]+1;
        }
    }
}
void Solve(){
    for(int i=0; i<m; i++){
        if(MAP[0][i]==0 && dist[0][i]==-1)
            bfs(0,i);
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0; i<m; i++){
        if(dist[n-1][i]!=-1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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