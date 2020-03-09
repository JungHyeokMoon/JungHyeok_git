#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> adjlist[1001];
vector<int> dist;
vector<int>parent;
int cnt=0;
#define Max 987654321
#define endl "\n"
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void Input(){
    cin>>n>>m;
    dist.resize(n+1,Max);
    parent.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({c,b});
        adjlist[b].push_back({c,a});
    }

}
void Solve(){
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        int hv=pq.top().second;
        int hc=pq.top().first;
        pq.pop();

        if(dist[hv]<hc ){
            continue;
        }
        for(int i=0; i<adjlist[hv].size(); i++){
            int nv=adjlist[hv][i].second;
            int nc=hc+adjlist[hv][i].first;
            if(nc<dist[nv]){
                dist[nv]=nc;
                pq.push({nc,nv});
                parent[nv]=hv; //어디에서 어디잇는지 명확히 한개밖에없음 최종적으로
            }
        }
    }
    cout<<n-1<<endl;
    for(int i=2; i<=n; i++){
        cout<<parent[i]<<" "<<i<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}