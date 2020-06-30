// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// int n, k;
// vector<bool> visited;
// const int MAX = 500000;
// bool isInside(int c)
// {
//     if (c >= 0 && c <= MAX)
//         return true;
//     return false;
// }
// void Init()
// {
//     cin >> n >> k;
//     visited.resize(MAX + 1, false);
// }
// int retNc(int hc, int idx)
// {
//     if (idx == 0)
//     {
//         return hc - 1;
//     }
//     else if (idx == 1)
//     {
//         return hc + 1;
//     }
//     else
//         return 2 * hc;
// }
// void Solve()
// {
//     queue<int> q;
//     q.push(n);
//     int time = 0;
//     while (1)
//     {
//         if (k > MAX)
//         {
//             cout << -1 << endl;
//             return;
//         }

//         int qsize = q.size();
//         for (int i = 0; i < qsize; i++)
//         {
//             int hc = q.front();
//             q.pop();
//             visited[hc] = true;
//             if (hc == k)
//             {
//                 cout << time << endl;
//                 return;
//             }
//             for (int i = 0; i < 3; i++)
//             {
//                 int nc = retNc(hc, i);
//                 if (!isInside(nc))
//                     continue;
//                 if (!visited[nc])
//                 {
//                     q.push(nc);
//                     visited[nc] = true;
//                 }
//             }
//         }
//         fill(visited.begin(), visited.end(), false);
//         time++;
//         k = k + time;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Init();
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, k;
vector<vector<int>> dist;
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
    dist.resize(MAX + 1, vector<int>(2, -1));
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
    queue<pair<int, int>> q;
    q.push({n, 0});
    dist[n][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        int hc = cur.first;
        int ht = cur.second;
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nc = retNc(hc, i);
            if (!isInside(nc))
                continue;
            if (dist[nc][(ht + 1) % 2] != -1)
                continue;
            dist[nc][(ht + 1) % 2] = dist[hc][ht % 2] + 1;
            q.push({nc, ht + 1});
        }
    }
    int time = 0;
    while (k <= MAX)
    {
        if (dist[k][time % 2] != -1 && dist[k][time % 2] <= time)
        {
            cout << time << endl;
            return;
        }
        time++;
        k = k + time;
    }
    cout << -1 << endl;
    return;
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
//처음에 bfs에 조건둘다맞는걸 찾으려다 디버깅이 너무 힘들어 우선돌려놓고 조건에 맞는 것을 답으로출력