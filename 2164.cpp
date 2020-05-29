#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
queue<int> q;
void Init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
}
void Solve()
{
    while (q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    return 0;
}