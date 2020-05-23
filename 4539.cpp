#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<int> Number;
void Input()
{
    cin >> n;
    Number.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Number[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << Number[i] << endl;
    // }
}
int POW(int num, int iter)
{
    int ret = 1;
    for (int i = 0; i < iter; i++)
    {
        ret *= num;
    }
    return ret;
}
int getLength(int num)
{
    int ret = 0;
    while (num != 0)
    {
        num /= 10;
        ret++;
    }
    return ret;
}
void Solve()
{
    for (int i = 0; i < n; i++)
    {
        // cout << getLength(Number[i]) << endl;
        int Length = getLength(Number[i]);
        for (int j = 1; j < Length; j++)
        {
            int division = Number[i] % POW(10, j);
            int idx = 0;
            while (division > 10)
            {
                division /= 10;
                idx++;
            }
            // cout << division << endl;
            if (division >= 5)
            {
                Number[i] = Number[i] - division * POW(10, idx);
                Number[i] = Number[i] + POW(10, idx + 1);
            }
            else
            {
                Number[i] = Number[i] - division * POW(10, idx);
            }
        }
        cout << Number[i] << endl;
    }
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