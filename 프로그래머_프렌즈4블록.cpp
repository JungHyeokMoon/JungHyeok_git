#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
const pair<int, int> d[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
bool Isinside(int y, int x, int m, int n)
{
    if (y >= 0 && y < m && x >= 0 && x < n)
        return true;
    return false;
}
void Down(int m, int n, vector<string> &board)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == ' ')
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    board[k + 1][j] = board[k][j];
                    board[k][j] = ' ';
                }
            }
        }
    }
}
bool Check(int y, int x, int m, int n, vector<string> &board)
{
    char temp = board[y][x];
    for (int i = 0; i < 4; i++)
    {
        int hy = y + d[i].first;
        int hx = x + d[i].second;

        if (!Isinside(hy, hx, m, n))
            return false;
        if (temp != board[hy][hx] || board[hy][hx] == ' ')
            return false;
    }
    for (int i = 0; i < 4; i++)
    {
        int hy = y + d[i].first;
        int hx = x + d[i].second;
        s.insert({hy, hx});
    }
    return true;
}
int Plus(vector<string> &board)
{
    int ret = 0;
    for (auto cur : s)
    {
        int hy = cur.first;
        int hx = cur.second;
        ret++;
        board[hy][hx] = ' ';
        s.erase({hy, hx});
    }
    return ret;
}
void Output(int m, int n, vector<string> &board)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int Solve(int m, int n, vector<string> &board)
{
    int ret = 0;
    int i = 1;
    while (1)
    {
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Check(i, j, m, n, board))
                {
                    // cout<<"hy: "<<i<<" hx: "<<j<<endl;
                    flag = true;
                }
            }
        }
        // if (i == 1)
        // {
        //     for (auto cur : s)
        //     {
        //         int hy = cur.first;
        //         int hx = cur.second;
        //         // ret++;
        //         // board[hy][hx] = ' ';
        //         // s.erase({hy, hx});
        //         cout << "hy : " << hy << " hx : " << hx << endl;
        //         cout << s.size() << endl;
        //     }
        //     break;
        // }
        if (!flag)
            break;
        ret += Plus(board);
        Down(m, n, board);
        // Output(m, n, board);
        // break;
    }
    return ret;
}
int solution(int m, int n, vector<string> board)
{
    int answer = Solve(m, n, board);
    return answer;
}