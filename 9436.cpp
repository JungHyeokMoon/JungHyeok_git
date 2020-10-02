#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool Check(vector<int> &roundRobin)
{
    int length = roundRobin.size();
    int temp = roundRobin[0];
    for (int i = 1; i < length; i++)
        if (temp != roundRobin[i])
            return false;
    return true;
}
void Solve()
{
    int n, t;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> t;
        vector<int> roundRobin(n, 0);
        int i = 0;
        while (1)
        {
            for (int k = 0; k < t; k++, i++)
                roundRobin[i % n]++;
                
            roundRobin.erase(roundRobin.begin() + ((i - 1) % n));
            i = (i - 1) % n;
            n--;

            if (Check(roundRobin))
            {
                cout << n << " " << roundRobin[0] << endl;
                break;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}