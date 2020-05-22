#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int k, n;
vector<int> v;

void Input()
{
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    // cout << *(v.begin() + k - 1) << endl;
}
void Solve()
{
    cout << "<";
    int index = 0;
    while (!v.empty())
    {
        index = (index + k - 1) % v.size();
        if (v.size() != 1)
        {
            cout << v[index] << ", ";
        }
        else
        {
            cout << v[index];
        }
        v.erase(v.begin() + index);
    }
    cout << ">";
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