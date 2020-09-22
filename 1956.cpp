#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int v,e;
vector<vector<int>> dist;
const int INF=1000000000;
void Init(){
    cin>>v>>e;
    dist.resize(v+1,vector<int>(v+1,INF));
    for(int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
}

void Floyd(){
    for(int k=1; k<=v; k++)
        for(int i=1; i<=v; i++)
            for(int j=1; j<=v; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
void Solve(){
    Floyd();
    // Print();
    int ret=INF;
    for(int i=1; i<=v; i++)
        ret=min(ret,dist[i][i]);

    if(ret==INF)
        cout<<-1<<endl;
    else
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

// void Print(){
//     for(int i=1; i<=v; i++){
//         for(int j=1; j<=v; j++){
//             if(dist[i][j]==INF)cout<<0<<" ";
//             else cout<<dist[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }