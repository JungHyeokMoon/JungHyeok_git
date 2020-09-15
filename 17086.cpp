#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<int>> MAP;
pair<int,int> dir[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int ret=0;
vector<pair<int,int>> shark;
bool IsInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m)
        return true;
    return false;
}
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>MAP[i][j];
            if(MAP[i][j]==1)
                shark.push_back({i,j});
        }
    }

    // for(auto i :MAP){
    //     for(auto j :i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(auto i :shark)
    //     cout<<i.first<<" "<<i.second<<endl;
}
void bfs(){
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    for(auto i :shark){
        dist[i.first][i.second]=0;
        q.push({i.first,i.second});
    }
    
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int hy=cur.first;
        int hx=cur.second;

        for(int i=0; i<8; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;
            if(!IsInside(ny,nx))continue;
            if(MAP[ny][nx]==1)continue;
            if(dist[ny][nx]!=-1)continue;
            q.push({ny,nx});
            dist[ny][nx]=dist[hy][hx]+1;
            ret=max(ret,dist[ny][nx]);
        }
    }

}
void Solve(){
    bfs();
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