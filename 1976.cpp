#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<int>> MAP;
vector<int> parent;
vector<int> route;
int Find(int u){
    if(u==parent[u])return u;
    else return parent[u]=Find(parent[u]);
}
void Merge(int u,int v){
    u=Find(u);
    v=Find(v);
    parent[v]=u;
}
void Init(){
    cin>>n>>m;
    MAP.resize(n+1,vector<int>(n+1));
    parent.resize(n+1);
    for(int i=1; i<=n; i++)
        parent[i]=i;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>MAP[i][j];
            if(MAP[i][j]==1){
                Merge(i,j);
            }
        }
    }


    route.resize(m);
    for(auto &i :route)
        cin>>i;

    
    // for(int i=1; i<=n; i++)
    //     cout<<parent[i]<<" ";
    // cout<<endl;

    // for(auto i :route)
    //     cout<<i<<" ";
    // cout<<endl;
}
void Solve(){
    // int temp=parent[route[0]];
    // for(int i=1; i<m; i++){
    //     // cout<<parent[route[i]]<<endl;
    //     if(temp!=parent[parent[route[i]]]){
    //         cout<<"NO"<<endl;
    //         return;
    //     }

    // }
    int temp=Find(route[0]);
    for(int i=1; i<m; i++){
        // cout<<parent[route[i]]<<endl;
        if(temp!=Find(route[i])){
            cout<<"NO"<<endl;
            return;
        }

    }
    cout<<"YES"<<endl;
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
