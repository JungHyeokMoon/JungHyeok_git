#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<int> arr; //Input
vector<bool> visited;
vector<int> ans;
void Input()
{
    cin >> n;
    arr.resize(n + 1);
    visited.resize(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

void dfs(int startNode, int CurrentNode)
{
    if (!visited[CurrentNode])
    {
        visited[CurrentNode] = true;
        dfs(startNode, arr[CurrentNode]);
    }
    else
    {
        if (CurrentNode == startNode)
        {
            ans.push_back(CurrentNode);
        }
    }
}
void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        dfs(i, i);
        visited = vector<bool>(n, false);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();

    return 0;
}