#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        } //좌측
        for (int l = 1; l <= k; l++)
        {
            cout << "*";
        } //중앙
        cout << "\n";
        k = k + 2;
    }
    return 0;
}