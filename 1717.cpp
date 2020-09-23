#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<int> parent;
int Find(int u){
    if(u==parent[u])return u;
    else return parent[u]=Find(parent[u]);
}
void Merge(int u, int v){
    u=Find(u);
    v=Find(v);
    if(u==v)return ;
    
    parent[v]=u;
}
void Init(){
    cin>>n;
    parent.resize(n+1);
    for(int i=0; i<=n; i++)
        parent[i]=i;
}
void Solve(){
    cin>>m;
    
    for(int i=0; i<m; i++){
        int command, a, b;
        cin>>command>>a>>b;
        if(command==0){
            Merge(a,b);
        }else{
            if(Find(a)==Find(b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
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