#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v,e,p;
vector<vector<pair<int,int>>> adjlist;
void Init(){
    cin>>v>>e>>p;
    adjlist.resize(v+1);
    for(int i=0; i<e; i++){
        int start,destination,cost;
        cin>>start>>destination>>cost;
        adjlist[start].push_back({destination,cost});
        adjlist[destination].push_back({start,cost});
    }
}
vector<long long> dijkstra(int start){
    vector<long long> dist(v+1,INT32_MAX);
    priority_queue<pair<long long,int>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        long long cost=-pq.top().first;
        int here=pq.top().second;

        pq.pop();

        if(dist[here]<cost)continue;

        for(int i=0; i<adjlist[here].size(); i++){
            int there=adjlist[here][i].first;
            long long nextCost=cost+adjlist[here][i].second;

            if(dist[there]>nextCost){
                pq.push({-nextCost,there});
                dist[there]=nextCost;
            }
        }
    }
    return dist;
}
void Solve(){
    vector<long long> startDist=dijkstra(1);
    long long shortestPath=startDist[v];
    long long startToGunWoo=startDist[p];
    vector<long long> midDist=dijkstra(p);
    long long gunWooToMasan=midDist[v];
    if(startToGunWoo+gunWooToMasan<=shortestPath)
        cout<<"SAVE HIM"<<endl;
    else
        cout<<"GOOD BYE"<<endl;
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