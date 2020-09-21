#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF=1000000000;
int n,k,s;
vector<vector<int>> dist;
void Init(){
    cin>>n>>k;
    dist.resize(n+1,vector<int>(n+1,INF));
    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
    }
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
    cin>>k;
    // Print();
    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==INF && dist[b][a]==INF)cout<<0<<endl;
        else if(dist[a][b]==INF)cout<<1<<endl;
        else cout<<-1<<endl;
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