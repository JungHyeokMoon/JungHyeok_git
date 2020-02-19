#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
long long k, n, m; //과자 한개의 가격 k, 과자의 갯수 n , 현재가진돈 m
void Input()
{
    cin >> k >> n >> m;
}
void Solve()
{
    if (m >= k * n)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << k * n - m << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();

    return 0;
}