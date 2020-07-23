// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<int> input;
// vector<bool> visited;
// vector<int> ret;
// void Init()
// {
//     cin >> n >> m;
//     visited.resize(10000, false);
//     input.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> input[i];
//     }
//     sort(input.begin(), input.end());
// }
// void Recursion(int k)
// {
//     if (ret.size() == m)
//     {
//         for (auto i : ret)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//         return;
//     }
//     for (int i = k; i < n; i++)
//     {
//         if (!visited[input[i]])
//         {
//             visited[input[i]] = true;
//             ret.push_back(input[i]);
//             Recursion(i + 1);
//             ret.pop_back();
//             visited[input[i]] = false;
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Init();
//     Recursion(0);
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    vector<int> combi(n, 1);
    for (int i = 0; i < m; i++)
        combi[i] = 0;

    do
    {
        int cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (cnt == m)
                break;
            if (combi[i] == 0)
            {
                cout << v[i] << " ";
                cnt++;
            }
        }
        cout << endl;
    } while (next_permutation(combi.begin(), combi.end()));
    return 0;
}