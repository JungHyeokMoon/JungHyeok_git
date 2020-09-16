#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<int>> MAP;
int n,m;
vector<pair<int,int>> white;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
bool IsInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m)
        return true;
    return false;
}
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<int>(m));
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<m; j++){
            MAP[i][j]=temp[j]-'0';
            if(MAP[i][j]==1)
                white.push_back({i,j});
        }
    }
}
void Output(vector<vector<int>>  dist){
    for(auto & i :dist){
        for(auto & j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>> bfs(){
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(m,-1));

    for(auto i :white){
        q.push({i.first,i.second});
        dist[i.first][i.second]=0;
    }

    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int hy=cur.first;
        int hx=cur.second;

        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;
            if(!IsInside(ny,nx))continue;
            if(dist[ny][nx]!=-1)continue;
            if(MAP[ny][nx])continue;
            q.push({ny,nx});
            dist[ny][nx]=dist[hy][hx]+1;
        }
    }
    return dist;
}
void Solve(){
    Output(bfs());
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