#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, c, w;
vector<int> namu;
int MAXHEIGHT = -1e9;
int ret = 0;
void Input()
{
    cin >> n >> c >> w;
    namu.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> namu[i];
        MAXHEIGHT = max(MAXHEIGHT, namu[i]);
    }
}
void Solve()
{
    for (int i = 1; i <= MAXHEIGHT; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (namu[j] >= i)
            {
                int piece = namu[j] / i;
                int cut;
                if (namu[j] % i == 0)
                {
                    cut = namu[j] / i - 1;
                }
                else
                {
                    cut = namu[j] / i;
                }
                if (piece * w * i > cut * c)
                {
                    sum = sum + piece * w * i - cut * c;
                }
            }
        }
        ret = max(ret, sum);
    }
    cout << ret << endl;
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