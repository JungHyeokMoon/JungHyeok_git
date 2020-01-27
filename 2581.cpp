#include <bits/stdc++.h>
using namespace std;
int m, n;
void Input()
{
    cin >> m >> n;
}
bool check[10001];
void eratos()
{
    for (int i = 2; i * i <= 10000; i++)
    {
        if (!check[i])
        {
            int k = 2 * i;
            while (k <= 10000)
            {
                check[k] = true; //소수가아닌것들 체크해버림
                k = k + i;
            }
        }
    }
}
int Sum = 0;
int Min = 0;
bool flag = false;
void Solve()
{
    eratos();
    check[0]=true;
    check[1]=true;
    for (int i = m; i <= n; i++)
    {
        if (!check[i])
        {
            if (!flag)
            {
                Min = i;
                flag = true;
            }
            Sum += i;
        }
    }

    if (Sum == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << Sum << "\n";
        cout << Min << "\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}