#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<int>> adjlist;
vector<bool> visited;
void Init(){
    cin>>n>>m;
    adjlist.resize(n);
    visited.resize(n);
    for(int i=0; i<m; i++){
        int start, destination;
        cin>>start>>destination;
        adjlist[start].push_back(destination);
        adjlist[destination].push_back(start);
    }
}
bool dfs(int cur,int depth){
    if(depth==4)
        return true;
    visited[cur]=true;

    for(auto next: adjlist[cur]){
        if(visited[next])continue;
        if(dfs(next,depth+1))
            return true;
    }
    visited[cur]=false;
    return false;
}
void Solve(){
    for(int i=0; i<n; i++){
        fill(visited.begin(),visited.end(),false);
        if(dfs(i,0)){
            cout<<1<<endl;
            return ;
        }
    }
    cout<<0<<endl;
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