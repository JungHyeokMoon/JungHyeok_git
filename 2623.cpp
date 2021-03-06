#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m;
vector<vector<int>> adjlist;
vector<int> indegree;
vector<int> result;
void Init()
{
    cin >> n >> m;
    adjlist.resize(n + 1);
    indegree.resize(n + 1);
    result.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int prev;
        cin >> prev;
        for (int j = 0; j < k - 1; j++)
        {
            int cur;
            cin >> cur;
            adjlist[prev].push_back(cur);
            indegree[cur]++;
            prev = cur;
        }
    }

}
void Solve()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
        {
            cout << 0 << endl;
            return;
        }
        int cur = q.front();
        q.pop();
        result[i] = cur;
        for (auto next : adjlist[cur])
            if (--indegree[next] == 0)
                q.push(next);
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << endl;
    
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