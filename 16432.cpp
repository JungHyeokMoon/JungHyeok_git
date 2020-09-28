#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<vector<int>> riceCake;
vector<int> ret;
vector<vector<bool>> visited;
void Init()
{
    cin >> n;
    riceCake.resize(n);
    visited.resize(n,vector<bool>(10,false));
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        riceCake[i].resize(m);
        for (auto &j : riceCake[i])
            cin >> j;
    }
}
bool dfs(int day, int prev)
{
    if (day == n)
    {
        for (auto i : ret)
            cout << i << " ";
        return true;
    }
    for (auto curCake : riceCake[day])
    {
        if (curCake != prev && !visited[day][curCake])
        {
            visited[day][curCake]=true;
            ret.push_back(curCake);
            if (dfs(day + 1, curCake) == true)
                return true;
            ret.pop_back();
            // visited[day][curCake]=false;
        }
    }
    return false;
}
void Solve()
{
    if (dfs(0, -1) == false)
        cout << -1 << endl;
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