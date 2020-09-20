#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<vector<pair<long long,int>>> adjlist;
int v1,v2;
int ret=0;
void Init(){
    cin>>n>>m;
    adjlist.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
    cin>>v1>>v2;
}
vector<long long> dijkstra(int start){
    vector<long long> dist(n+1,INT32_MAX);
    priority_queue<pair<long long,int>> pq;
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        long long cost=-pq.top().first;
        int here=pq.top().second;

        pq.pop();

        if(dist[here]<cost)
            continue;
        
        for(int i=0; i<adjlist[here].size(); i++){
            int there=adjlist[here][i].first;
            long long nextCost=cost+adjlist[here][i].second;
            if(dist[there]>nextCost){
                dist[there]=nextCost;
                pq.push({-nextCost,there});
            }
        }
    }

    return dist;
}
void Solve(){
    vector<long long > dist1=dijkstra(1);
    vector<long long> dist2=dijkstra(v1);
    vector<long long> dist3=dijkstra(v2);
    long long sum1=dist1[v1]+dist2[v2]+dist3[n];
    long long sum2=dist1[v2]+dist3[v1]+dist2[n];
    if(sum1 >=INT32_MAX && sum2>=INT32_MAX){
        cout<<-1<<endl;
        return;
    }
    long long ret=min(sum1,sum2);
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