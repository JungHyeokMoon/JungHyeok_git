#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m;
vector<int> sight;
vector<vector<pair<int, long long>>> adjlist;
const long long INF = 1LL << 60;
void Init()
{
    cin >> n >> m;
    sight.resize(n);
    adjlist.resize(n);
    for (int i = 0; i < n; i++)
        cin >> sight[i];
    sight[n-1]=0;
    for (int i = 0; i < m; i++)
    {
        int start, end;
        long long cost;
        cin >> start >> end >> cost;
        if(sight[start]|| sight[end])continue;
        adjlist[start].push_back({end, cost});
        adjlist[end].push_back({start, cost});
    }
}
vector<long long> dijkstra(int start)
{
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        long long cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int j = 0; j < adjlist[here].size(); j++)
        {
            int there = adjlist[here][j].first;
            long long nextCost = cost + adjlist[here][j].second;

            if (dist[there] < nextCost)
                continue;
            dist[there] = nextCost;
            pq.push({-nextCost, there});
        }
    }
    return dist;
}
void Solve()
{
    vector<long long> dist = dijkstra(0);
    if(dist[n-1]==INF)cout<<-1<<endl;
    else cout<<dist[n-1]<<endl;
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