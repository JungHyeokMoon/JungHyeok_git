#include <bits/stdc++.h>
#define endl "\n"
#define EMPTY 0
#define GREEN 1
#define RED 2
#define FLOWER 3
using namespace std;
int n, m, g, r;
vector<vector<int>> MAP; //0 은 호수, 1은 배양액을 뿌릴수없는땅, 2는 배양액을 뿌릴수 있는 땅
int ret;
vector<pair<int, int>> GrowLand;
int combi[10];
int glSize;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isInside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < m)
        return true;
    return false;
}
void Init()
{
    cin >> n >> m >> g >> r;
    MAP.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
            {
                GrowLand.push_back({i, j});
            }
        }
    }
}
int getAnswer()
{
    int cnt = 0;
    pair<int, int> state[52][52];
    queue<pair<int, int>> q;
    for (int i = 0; i < glSize; i++)
    {
        if (combi[i] == RED || combi[i] == GREEN)
        {
            state[GrowLand[i].first][GrowLand[i].second] = {0, combi[i]};
            q.push(GrowLand[i]);
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();

        int curtime = state[cur.first][cur.second].first;
        int curcolor = state[cur.first][cur.second].second;
        q.pop();

        if (state[cur.first][cur.second].second == FLOWER)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dir[i].first;
            int nx = cur.second + dir[i].second;

            if (!isInside(ny, nx))
                continue;
            if (MAP[ny][nx] == 0)
                continue;
            if (state[ny][nx].second == EMPTY)
            {
                state[ny][nx] = {curtime + 1, curcolor};
                q.push({ny, nx});
            }
            else if (state[ny][nx].second == RED)
            {
                if (curcolor == GREEN && curtime + 1 == state[ny][nx].first)
                {
                    state[ny][nx].second = FLOWER;
                    cnt++;
                }
            }
            else if (state[ny][nx].second == GREEN)
            {
                if (curcolor == RED && curtime + 1 == state[ny][nx].first)
                {
                    state[ny][nx].second = FLOWER;
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

void Solve()
{
    glSize = GrowLand.size();
    fill(combi + glSize - g - r, combi + glSize - r, GREEN);
    fill(combi + glSize - r, combi + glSize, RED);
    do
    {
        ret = max(ret, getAnswer());
    } while (next_permutation(combi, combi + glSize));
    cout << ret << endl;
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