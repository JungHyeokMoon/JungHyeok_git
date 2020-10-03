#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<int> box;
vector<int> dp;
void Init()
{
    cin >> n;
    box.resize(n);
    for (auto &i : box)
        cin >> i;

    dp.resize(n+1, -1);
}
int BoxPut(int start)
{
    int &ret = dp[start + 1];
    if (ret != -1)
        return ret;

    ret = 0;

    for (int next = start + 1; next < n; next++)
    {
        if (start == -1 || box[start] < box[next])
        {
            int candidate = BoxPut(next)+1;
            if(candidate>ret)
                ret=candidate;
        }
    }

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    cout << BoxPut(-1) << endl;
    return 0;
}