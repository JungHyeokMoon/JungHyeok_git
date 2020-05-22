#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool visited[101][101];
int ans = 0;
void Solve()
{
    int x1, x2, y1, y2;
    for (int i = 0; i < 4; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        for (int j = x1; j < x2; j++)
        {
            for (int k = y1; k < y2; k++)
            {
                // cout << "j, k " << j << " " << k << endl;
                visited[j][k] = true;
            }
        }
    }

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (visited[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}