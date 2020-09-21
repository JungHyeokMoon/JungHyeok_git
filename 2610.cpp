#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
const int INF=1000000000;
vector<vector<int>> dist;
vector<int> parent;
vector<int> ret;
vector<vector<int>> group;
void Init(){
    cin>>n>>m;
    dist.resize(n+1,vector<int>(n+1,INF));
    for(int i=0; i<m;i++){
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=1;
    }
    parent.resize(n+1);
    for(int i=1; i<=n; i++)
        parent[i]=i;
    group.resize(n+1);
}
int Find(int u){
    if(u==parent[u])return u;
    else return parent[u]=Find(parent[u]);
}
void Merge(int u, int v){
    u=Find(u);
    v=Find(v);
    if(u==v)return;
    parent[u]=v;
}
void Print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==INF)cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Floyd(){
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

}
void Solve(){
    Floyd();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]!=INF)
                Merge(i,j);
        }
    }
    
    
    for(int i=1; i<=n; i++)
        group[parent[i]].push_back(i);

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(group[i].empty())continue;
        else{
            int candidate=group[i][0];
            int temp=INF;
            for(auto j : group[i]){
                int hc=0;
                for(auto k :group[i]){
                    if(j==k)continue;
                    hc=max(hc,dist[j][k]);
                }
                if(hc<temp){
                    temp=hc;
                    candidate=j;
                }
                    
            }
            ret.push_back(candidate);
        }
    }
    cout<<ret.size()<<endl;
    sort(ret.begin(),ret.end());
    for(auto i :ret)
        cout<<i<<endl;
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