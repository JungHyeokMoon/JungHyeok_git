#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<int> input;
vector<bool> visited;
vector<int> ret;
void Init()
{
    cin >> n >> m;
    visited.resize(10000, false);
    input.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
}
void Recursion(int k)
{
    if (ret.size() == m)
    {
        for (auto i : ret)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = k; i < n; i++)
    {
        if (!visited[input[i]])
        {
            visited[input[i]] = true;
            ret.push_back(input[i]);
            Recursion(i + 1);
            ret.pop_back();
            visited[input[i]] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Recursion(0);
    return 0;
}