#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<pair<int,int>>> adjlist;
void Init(){
    cin>>n>>m;
    adjlist.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
}
int bfs(int start,int destination){
    vector<int> dist(n+1,-1);
    dist[start]=0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        if(cur==destination)
            return dist[destination];
        for(auto next:adjlist[cur]){
            if(dist[next.first]!=-1)continue;
            q.push(next.first);
            dist[next.first]=dist[cur]+next.second;
        }
    }
}
void Solve(){
    for(int i=0; i<m; i++){
        int start,destination;
        cin>>start>>destination;
        cout<<bfs(start,destination)<<endl;
    }
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