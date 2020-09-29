#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int r,c;
vector<vector<char>> MAP;
vector<vector<bool>> visited;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
pair<int,int> ret={0,0};
bool IsInside(int y, int x){
    if(y>=0 && y<r && x>=0 && x<c)
        return true;
    return false;
}
void Init(){
    cin>>r>>c;
    MAP.resize(r,vector<char>(c));
    visited.resize(r,vector<bool>(c,false));
    for(auto & i :MAP)
        for(auto &j : i)
            cin>>j;
    
}
void Print(){
    for(int i=0 ;i<r; i++){
        for(int j=0; j<c; j++){
            cout<<visited[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void bfs(int y, int x){
    queue<pair<int,int>>q;
    visited[y][x]=true;
    int wolf=0;
    int sheep=0;
    q.push({y,x});
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        // cout<<cur.first<<" "<<cur.second<<endl;
        if(MAP[cur.first][cur.second]=='v')
            wolf++;
        else if(MAP[cur.first][cur.second]=='k')
            sheep++;
        for(int i=0; i<4; i++){
            int ny=cur.first+dir[i].first;
            int nx=cur.second+dir[i].second;
            if(!IsInside(ny, nx))continue;
            if(MAP[ny][nx]=='#')continue;
            if(visited[ny][nx]==true)continue;
            q.push({ny,nx});
            visited[ny][nx]=true;
            // if(MAP[ny][nx]=='v')
            //     wolf++;
            // else if(MAP[ny][nx]=='k')
            //     sheep++;
        }
    }
    if(sheep>wolf)
        wolf=0;
    else
        sheep=0;
    ret.first+=sheep;
    ret.second+=wolf;
}
void Solve(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if((MAP[i][j]=='v'||MAP[i][j]=='k') && !visited[i][j]){
                bfs(i,j);
                // Print();
                // cout<<"----------------------"<<endl;
                // cout<<i<<" "<<j<<" "<<ret.first<<" "<<ret.second<<endl;
            }
        }
    }
    cout<<ret.first<<" "<<ret.second<<endl;
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