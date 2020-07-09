#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
pair<int, int> pw(int n, int k)
{
    if (n == 2)
    {
        if (k == 0)
            return {1, 1};
        else if (k == 1)
            return {1, 2};
        else if (k == 2)
            return {2, 2};
        else
            return {2, 1};
    }
    // cout << "n : " << n << " k : " << k << endl;
    int divide = n / 2;
    int portion = k / (divide * divide);
    pair<int, int> res;
    if (portion == 0)
    {
        res = pw(divide, k % (divide * divide));
        // cout << "h0 :" << res.first << " " << res.second << endl;
        swap(res.first, res.second);
        return res;
    }
    else if (portion == 1)
    {
        res = pw(divide, k % (divide * divide));
        // cout << "h1 :" << res.first << " " << res.second << endl;
        res.second += divide;
        return res;
    }
    else if (portion == 2)
    {
        res = pw(divide, k % (divide * divide));
        // cout << "h2 :" << res.first << " " << res.second << endl;
        res.first += divide;
        res.second += divide;
        return res;
    }
    else
    {
        res = pw(divide, k % (divide * divide));
        // cout << "h3 :" << res.first << " " << res.second << endl;
        pair<int, int> temp = {2 * divide - (res.second - 1), divide - (res.first - 1)};
        return temp;
    }
}
void Solve()
{
    cin >> n >> m;
    pair<int, int> ret = pw(n, m - 1);
    cout << ret.first << " " << ret.second << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}