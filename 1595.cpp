#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<pair<int,int>> adjlist [10000+1];
int ret=0;
void Init(){
    int a,b,c;
    while(cin>>a>>b>>c){
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
}

vector<int> dijkstra(int start){
    vector<int> dist(10000+1,INT32_MAX);
    priority_queue<pair<int,int>> pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;

        pq.pop();

        if(dist[here]<cost)
            continue;

        for(int i=0; i<adjlist[here].size(); i++){
            int there=adjlist[here][i].first;
            int nextCost=cost+adjlist[here][i].second;

            if(dist[there]>nextCost){
                ret=max(ret,nextCost);
                pq.push({-nextCost,there});
                dist[there]=nextCost;
            }
        }
    }
    return dist;
}
void Solve(){
    int start;
    for(int i=1; i<=10000; i++){
        if(adjlist[i].empty())continue;
        start=i;
        break;
    }
    vector<int> dist=dijkstra(start);
    
    int temp=0;
    for(int i=1; i<=10000; i++){
        if(dist[i]!=INT32_MAX && dist[i]>temp){
            temp=dist[i];
            start=i;
        }
    }
    dist=dijkstra(start);
    for(int i=1; i<=10000; i++){
        if(dist[i]!=INT32_MAX && dist[i]>temp){
            temp=dist[i];
        }
    }
    
    ret=temp;
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