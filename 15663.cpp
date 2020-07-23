// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<bool> visited;
// vector<int> arr;
// vector<int> Combi;
// set<string> s;
// void Input()
// {
//     cin >> n >> m;
//     visited.resize(n, false);
//     arr.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr.begin(), arr.end());
// }
// void Make_Combi(int depth)
// {
//     if (depth == m)
//     {
//         string temp = "";
//         int length = Combi.size();
//         for (int i = 0; i < length; i++)
//         {
//             temp += (Combi[i] + '0');
//             if (i != length - 1)
//             {
//                 temp.push_back(' ');
//             }
//         }
//         if (s.find(temp) == s.end())
//         {
//             s.insert(temp);
//             for (int i = 0; i < length; i++)
//             {
//                 cout << Combi[i] << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             Combi.push_back(arr[i]);
//             Make_Combi(depth + 1);
//             Combi.pop_back();
//             visited[i] = false;
//         }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Input();
//     Make_Combi(0);
//     return 0;
// }

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n, m;
// vector<int> arr;
// vector<bool> visited;
// vector<int> ret;
// set<string> s;
// void Init()
// {
//     cin >> n >> m;
//     arr.resize(n);
//     visited.resize(n, false);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr.begin(), arr.end());
// }
// void Recursion(int k)
// {
//     if (ret.size() == m)
//     {
//         string str;
//         for (int i = 0; i < ret.size(); i++)
//         {
//             str += (ret[i] + '0');
//             if (i != ret.size() - 1)
//             {
//                 str.push_back(' ');
//             }
//         }
//         if (s.find(str) == s.end())
//         {
//             s.insert(str);
//             // cout << str << endl;
//             for (int i = 0; i < ret.size(); i++)
//             {
//                 cout << ret[i] << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             ret.push_back(arr[i]);
//             Recursion(i + 1);
//             ret.pop_back();
//             visited[i] = false;
//         }
//     }
// }
// // void Output()
// // {
// //     for (auto i : s)
// //     {
// //         cout << i << endl;
// //     }
// // }
// void Solve()
// {
//     Recursion(0);
//     // Output();
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Init();
//     Solve();
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
    do
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << " ";
        reverse(v.begin() + m, v.end());
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}