#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int r, c;
const pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<char>> MAP;
vector<vector<int>> jihoondist;
vector<vector<bool>> firevisited;
queue<pair<int, int>> jihoon;
queue<pair<int, int>> fire;
bool isinside(int y, int x)
{
    if (y >= 0 && y < r && x >= 0 && x < c)
        return true;
    return false;
}
void Init()
{
    cin >> r >> c;
    MAP.resize(r, vector<char>(c, 0));
    jihoondist.resize(r, vector<int>(c, -1));
    firevisited.resize(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            if (str[j] == 'J')
            {
                jihoon.push({i, j});
                jihoondist[i][j] = 0;
            }
            if (str[j] == 'F')
            {
                fire.push({i, j});
                firevisited[i][j] = true;
            }
            MAP[i][j] = str[j];
        }
    }

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << MAP[i][j] << "";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}
void Output()
{
    cout << "jihoondist : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << jihoondist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "firevisited : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << firevisited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Solve()
{
    while (true)
    {
        int fireSize = fire.size();
        for (int i = 0; i < fireSize; i++)
        {
            int hy = fire.front().first;
            int hx = fire.front().second;

            fire.pop();

            for (int j = 0; j < 4; j++)
            {
                int ny = hy + d[j].first;
                int nx = hx + d[j].second;
                if (!isinside(ny, nx))
                    continue;
                if (MAP[ny][nx] == '#')
                    continue;
                if (firevisited[ny][nx] == true)
                    continue; //불이 이미 방문했으면 continue

                fire.push({ny, nx});
                firevisited[ny][nx] = true;
            }
        }

        int Jsize = jihoon.size();
        if (Jsize == 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        for (int i = 0; i < Jsize; i++)
        {
            int hy = jihoon.front().first;
            int hx = jihoon.front().second;
            // cout << "here" << endl;
            jihoon.pop();

            if (hy == 0 || hy == r - 1 || hx == 0 || hx == c - 1)
            {
                //거리출력
                cout << jihoondist[hy][hx] + 1 << endl;
                return;
            }
            for (int j = 0; j < 4; j++)
            {
                int ny = hy + d[j].first;
                int nx = hx + d[j].second;
                if (!isinside(ny, nx))
                {
                    // cout << 1 << endl; //밖으로나갔을때
                    // cout << jihoondist[hy][hx] + 1 << endl;
                    continue;
                    // return;
                }
                if (MAP[ny][nx] == '#')
                {
                    // cout << 2 << endl;
                    continue; //벽일때
                }
                if (firevisited[ny][nx] == true)
                {
                    // cout << 3 << endl;
                    continue; //불이 붙었을때
                }
                if (jihoondist[ny][nx] >= 0)
                {
                    // cout << 4 << endl;
                    continue; //방문했거나
                }

                // cout << "jihoon ny,nx : " << ny << " , " << nx << endl;
                jihoon.push({ny, nx});                       // 큐에넣고
                jihoondist[ny][nx] = jihoondist[hy][hx] + 1; // 시간체크
            }
        }
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