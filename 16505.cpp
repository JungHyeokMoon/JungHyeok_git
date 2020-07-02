#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<char>> MAP;
// char star[2][2] = {
//     {'*', '*'},
//     {'*', ' '}};
void Recursion(int n, int y, int x)
{
    if (n == 1)
    {
        MAP[y][x] = '*';
        // for (int i = 0; i < 2; i++)
        // {
        //     for (int j = 0; j < 2; j++)
        //     {
        //         MAP[y + i][x + j] = star[i][j];
        //     }
        // }
        return;
    }
    int k = n / 2;
    // cout << k << endl;
    Recursion(k, y, x);
    Recursion(k, y + k, x);
    Recursion(k, y, x + k);
}
void Output()
{
    int N = (1 << n);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
}
void Solve()
{
    cin >> n;
    MAP.resize((1 << n), vector<char>((1 << n), ' '));
    Recursion((1 << n), 0, 0);
    Output();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
