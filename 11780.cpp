#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
vector<vector<int>> dist;
vector<vector<int>> nxt;
void Init(){
    cin>>n>>m;
    dist.resize(n+1,vector<int>(n+1,1e9+1));
    nxt.resize(n+1,vector<int>(n+1));
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        nxt[a][b]=b;
    }
}
void Floyd(){
    for(int k=1; k<=n ; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n ; j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }
}
void Print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==1e9+1 || i==j)cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)cout<<0<<endl;
            else{
                vector<int> path;
                int cur=i;
                while(cur!=j){
                    path.push_back(cur);
                    cur=nxt[cur][j];
                }
                path.push_back(cur);
                cout<<path.size()<<" ";
                for(auto i :path)
                    cout<<i<<" ";
                cout<<endl;
            }
        }
    }
}
void Solve(){
    Floyd();
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