#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, k;
vector<vector<int>> MAP;
vector<vector<vector<int>>> sticker;
vector<vector<int>> temp2;
void Init()
{
    cin >> n >> m >> k;
    MAP.resize(n, vector<int>(m, 0));

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> temp(r, vector<int>(c));
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                cin >> temp[j][k];

        sticker.push_back(temp);
    }

    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < sticker[i].size(); j++)
    //     {
    //         for (int k = 0; k < sticker[i][j].size(); k++)
    //         {
    //             cout << sticker[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
}
void Output()
{
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[0].size(); j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool pastable(int x, int y, vector<vector<int>> &stk)
{
    int r = stk.size();
    int c = stk[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (MAP[x + i][y + j] == 1 && stk[i][j] == 1)
                return false;
        }
    }
    return true;
}
void past(int x, int y, vector<vector<int>> &stk)
{
    int r = stk.size();
    int c = stk[0].size();

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (stk[i][j] == 1)
                MAP[x + i][y + j] = stk[i][j];
}
vector<vector<int>> &rotation(vector<vector<int>> &stk)
{
    temp2.clear();
    int r = stk.size();
    int c = stk[0].size();
    swap(r, c);
    temp2.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp2[i][j] = stk[c - 1 - j][i];
    return temp2;
}
int getAnswer()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (MAP[i][j] == 1)
                cnt++;

    return cnt;
}
void Solve()
{
    for (int i = 0; i < sticker.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (j != 0)
                sticker[i] = rotation(sticker[i]);
            int r = sticker[i].size();
            int c = sticker[i][0].size();
            for (int k = 0; k <= n - r; k++)
            {
                for (int l = 0; l <= m - c; l++)
                {
                    if (pastable(k, l, sticker[i]))
                    {
                        past(k, l, sticker[i]);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
    }
    cout << getAnswer() << endl;
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