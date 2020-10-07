#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int k;
void dfs(int cur, int color, vector<int> &visited, vector<vector<int>> &adjlist, bool &flag)
{
    visited[cur] = color;

    for (auto next : adjlist[cur])
    {
        if (visited[next] == 0)
        {
            if (color == 1)
                dfs(next, 2, visited, adjlist, flag);
            else
                dfs(next, 1, visited, adjlist, flag);
        }
        else
        {
            if (visited[next] == color)
            {
                flag = false;
                return;
            }
            else
                continue;
        }
    }
}
void Solve()
{
    cin >> k;
    while (k--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adjlist(v + 1);
        vector<int> visited(v + 1, 0);
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        bool flag = true;
        for (int i = 1; i <= v; i++)
        {
            if (visited[i] == 0)
                dfs(i, 1, visited, adjlist, flag);
        }

        flag ? cout<<"YES"<<endl :cout<<"NO"<<endl;
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