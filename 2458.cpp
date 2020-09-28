#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<int>> dist;
int n,m;
const int INF=1000000000;
int ret=0;
void Print(){
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==INF)cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Init(){
    cin>>n>>m;
    dist.resize(n+1,vector<int>(n+1,INF));
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
    }

    // Print();
}

void Floyd(){
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++)
            if(dist[i][j]!=INF || dist[j][i]!=INF)cnt++;
        
        if(cnt==n-1)ret++;
    }
}
void Solve(){
    Floyd();

    // Print();
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