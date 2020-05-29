// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int num;
// stack<pair<int, int>> stk;
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int num;
//         cin >> num;

//         while (!stk.empty())
//         {
//             if (stk.top().second > num)
//             {
//                 cout << stk.top().first << " ";
//                 break;
//             }
//             stk.pop();
//         }

//         if (stk.empty())
//         {
//             cout << "0 ";
//         }
//         stk.push({i + 1, num});
//     }
//     return 0;
// }
// //

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// int n;
// vector<int> arr;
// void Input()
// {
//     cin >> n;
//     arr.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
// }
// void Solve()
// {
//     stack<pair<int, int>> stk;
//     for (int i = 0; i < n; i++)
//     {
//         if (!stk.empty())
//         {
//             while (!stk.empty() && stk.top().second < arr[i])
//             {
//                 stk.pop();
//             }
//             if (stk.empty())
//             {
//                 cout << 0 << " ";
//             }
//             else
//             {
//                 cout << stk.top().first << " ";
//             }
//         }
//         else
//         {
//             cout << 0 << " ";
//         }
//         stk.push({i + 1, arr[i]});
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Input();
//     Solve();
//     return 0;
// }
