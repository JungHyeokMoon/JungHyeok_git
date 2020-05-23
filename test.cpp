#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int func4(int n)
{
    int val = 1;
    while (val * 2 <= n)
        val *= 2;
    return val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        cout << func4(num) << endl;
    }
    return 0;
}