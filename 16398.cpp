#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<vector<int>> MAP;
typedef struct edge
{
    int start, end, cost;
    bool operator<(const edge &e)
    {
        return cost < e.cost;
    }
    edge(int s, int e, int c) : start(s), end(e), cost(c) {}
} edge;
vector<edge> e;
vector<int> parent;
int Find(int u)
{
    if (u == parent[u])
        return u;
    else
        return parent[u] = Find(parent[u]);
}
void Merge(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return;
    parent[v] = u;
}
void Init()
{
    cin >> n;
    MAP.resize(n, vector<int>(n));
    parent.resize(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            if (i < j)
                e.push_back(edge(i, j, MAP[i][j]));
        }
    }
}
void Solve()
{
    sort(e.begin(), e.end());
    int cnt=0;
    long long ret=0;
    for(auto i :e){
        if(Find(i.start)!=Find(i.end)){
            Merge(i.start,i.end);
            ret+=i.cost;
            cnt++;
        }
        if(cnt==n-1)break;
    }
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