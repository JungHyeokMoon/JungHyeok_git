#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<vector<int>> dist;
vector<vector<int>> MAP;
int n,m;
pair<int,int> destination;
bool IsInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m)
        return true;
    return false;
}
pair<int, int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>MAP[i][j];
            if(MAP[i][j]==2)
                destination={i,j};
        }
    }

    // for(auto i : MAP){
    //     for(auto j : i ){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
}
void bfs(){
    dist.resize(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    dist[destination.first][destination.second]=0;
    q.push({destination.first,destination.second});
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;

        q.pop();


        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;
            
            if(!IsInside(ny,nx))continue;
            if(dist[ny][nx]!=-1)continue;
            if(MAP[ny][nx]==0)continue;
            q.push({ny,nx});
            dist[ny][nx]=dist[hy][hx]+1;
        }
    }
}
void Print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j]!=-1)cout<<dist[i][j]<<" ";
            else{
                if(MAP[i][j]==0)cout<<0<<" ";
                else cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
}
void Solve(){
    bfs();
    Print();
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