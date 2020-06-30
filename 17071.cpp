#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, k;
vector<bool> visited;
const int MAX = 500000;
bool isInside(int c)
{
    if (c >= 0 && c <= MAX)
        return true;
    return false;
}
void Init()
{
    cin >> n >> k;
    visited.resize(MAX + 1, false);
}
int retNc(int hc, int idx)
{
    if (idx == 0)
    {
        return hc - 1;
    }
    else if (idx == 1)
    {
        return hc + 1;
    }
    else
        return 2 * hc;
}
void Solve()
{
    queue<int> q;
    q.push(n);
    int time = 0;
    while (1)
    {
        if (k > MAX)
        {
            cout << -1 << endl;
            return;
        }

        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int hc = q.front();
            q.pop();
            visited[hc] = true;
            if (hc == k)
            {
                cout << time << endl;
                return;
            }
            for (int i = 0; i < 3; i++)
            {
                int nc = retNc(hc, i);
                if (!isInside(nc))
                    continue;
                if (!visited[nc])
                {
                    q.push(nc);
                    visited[nc] = true;
                }
            }
        }
        fill(visited.begin(), visited.end(), false);
        time++;
        k = k + time;
    }
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