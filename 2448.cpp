#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<vector<char>> MAP;
char star[3][5] = {
    {' ', ' ', '*', ' ', ' '},
    {' ', '*', ' ', '*', ' '},
    {'*', '*', '*', '*', '*'}};
void Recursion(int n, int y, int x)
{
    if (n == 3)
    {
        if (x >= 2)
        {
            x = x - 2;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                MAP[y + i][x + j] = star[i][j];
            }
        }
        return;
    }
    int divide = n / 2;
    Recursion(divide, y, x);
    Recursion(divide, y + divide, x - divide);
    Recursion(divide, y + divide, x + divide);
}
void Output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
}
void Solve()
{
    cin >> n;
    MAP.resize(n, vector<char>(2 * n - 1, ' '));
    Recursion(n, 0, n - 1);
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
