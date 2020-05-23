#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<vector<int>> MAP;
int n, m;
// int numbefOfOne;
vector<int> row;
vector<int> col;
int N;
void Input()
{
    cin >> n >> m;
    MAP.resize(n, vector<int>(m, 0));
    row.resize(n);
    col.resize(m);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == '1')
            {
                row[i]++;
                col[j]++;
            }

            MAP[i][j] = temp[j] - '0';
        }
    }
}
void Count()
{
    for (int i = 0; i < n; i++)
    {
        if (row[i])
    }
}
void Solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}