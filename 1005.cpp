#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t;
vector<vector<int>> adjlist;
vector<int> indegree;
vector<int> buildingTime;
int n, k;
int w;
void InitFirst()
{

    cin >> n >> k;
    adjlist.resize(n + 1);
    indegree.resize(n + 1);
    buildingTime.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> buildingTime[i];
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        indegree[b]++;
    }
    cin >> w;
}
void InitLast()
{
    for (int i = 0; i <= n; i++)
        if (!adjlist[i].empty())
            adjlist[i].clear();

    adjlist.clear();
    indegree.clear();
    buildingTime.clear();
}
int Build()
{
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto j : adjlist[i])
    //         cout << j << " ";
    //     cout << endl;
    // }
    // cout << "---------------------------" << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << buildingTime[i] << " ";
    // cout << endl;

    // cout << "---------------------------" << endl;

    // for (int i = 1; i <= n; i++)
    //     cout << indegree[i] << " ";
    // cout << endl;
    // cout << "---------------------------" << endl;
    // cout << w << endl;
    // cout << "---------------------------" << endl;
    queue<int> q;
    vector<int> dist(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dist[i]=buildingTime[i];
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        // cout << "cur: " << cur << " " << dist[cur] << endl;
        // if (curBuilding == w )
        //     return curTime;
        if(cur==w)
            return dist[cur];
        for (auto nextBuilding : adjlist[cur])
        {
            
            int nextTime = dist[cur] + buildingTime[nextBuilding];
            if(dist[nextBuilding]<nextTime)
                dist[nextBuilding]=nextTime;
            // cout<<"next : "<<nextBuilding<<" "<<nextTime<<endl;
            if (--indegree[nextBuilding] == 0)
                q.push({nextBuilding});
        }
    }

}
void Solve()
{
    cin >> t;
    while (t--)
    {
        InitFirst();
        cout <<Build() << endl;
        InitLast();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}