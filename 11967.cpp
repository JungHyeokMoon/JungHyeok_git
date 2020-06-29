#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
vector<vector<bool>> light;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> v[100][100];
vector<vector<bool>> visited;
bool isInside(int y, int x) //범위체크함수
{
    if (y >= 0 && y < n && x >= 0 && x < n)
        return true;
    return false;
}
void Init() //초기화
{
    cin >> n;
    light.resize(n, vector<bool>(n, false));
    visited.resize(n, vector<bool>(n, false));
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x - 1][y - 1].push_back({a - 1, b - 1});
    }
    light[0][0] = true;
}
int countLight() //빛개수 세주는함수
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (light[i][j] == true)
                ret++;
        }
    }
    return ret;
}
bool bfs()
{
    bool ret = false;
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int hy = cur.first;
        int hx = cur.second;
        if (!v[hy][hx].empty())
        {
            for (int i = 0; i < v[hy][hx].size(); i++)
            {
                int ly = v[hy][hx][i].first;
                int lx = v[hy][hx][i].second;
                if (!light[ly][lx])
                {
                    light[ly][lx] = true;
                    ret = true;
                }
            }
            v[hy][hx].clear();
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!isInside(ny, nx))
                continue;
            if (light[ny][nx] == true && visited[ny][nx] == false)
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    return ret;
}
void Solve()
{
    while (1)
    {
        if (!bfs())
            break;
        for (int i = 0; i < n; i++)
        {
            fill(visited[i].begin(), visited[i].end(), false);
        }
    }
    cout << countLight() << endl; //빛개수세주는함수
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