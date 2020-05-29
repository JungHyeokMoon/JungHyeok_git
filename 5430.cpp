// #include <bits/stdc++.h>
// using namespace std;

// int t;
// char left_bracket;
// char right_bracket;
// char comma;
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         int flag = 0;
//         int R = 0;
//         string P;
//         cin >> P; //함수받는거임

//         deque<int> dq;

//         int n;
//         cin >> n;

//         cin >> left_bracket;
//         for (int j = 0; j < n; j++)
//         {
//             if (j != n - 1)
//             {
//                 int num;
//                 cin >> num;
//                 dq.push_back(num);
//                 cin >> comma;
//             }
//             else
//             {
//                 int num;
//                 cin >> num;
//                 dq.push_back(num);
//             }
//         }
//         cin >> right_bracket;
//         //숫자입력 다 받고 덱에 집어넣었음

//         int len = P.size();

//         for (int j = 0; j < len; j++)
//         {
//             if (P[j] == 'D')
//             {
//                 if (!dq.empty())
//                 {
//                     if (R % 2 == 0)
//                     {
//                         dq.pop_front();
//                     }
//                     else
//                     {
//                         dq.pop_back();
//                     }
//                 }
//                 else
//                 {
//                     cout << "error"
//                          << "\n";
//                     flag = 1;
//                     break;
//                 }
//             } //D
//             else
//             {
//                 R++;
//             }
//         }

//         //출력 부분
//         if (!flag)
//         {
//             cout << "[";
//             if (R % 2 == 0)
//             {
//                 while (!dq.empty())
//                 {
//                     if (dq.size() == 1)
//                     {
//                         cout << dq.front();
//                         dq.pop_front();
//                     }
//                     else
//                     {
//                         cout << dq.front() << ",";
//                         dq.pop_front();
//                     }
//                 }
//             }
//             else
//             {
//                 while (!dq.empty())
//                 {
//                     if (dq.size() == 1)
//                     {
//                         cout << dq.back();
//                         dq.pop_back();
//                     }
//                     else
//                     {
//                         cout << dq.back() << ",";
//                         dq.pop_back();
//                     }
//                 }
//             }
//             cout << "]"
//                  << "\n";
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
deque<int> dq;
void Output(int r_count)
{
    cout << "[";
    while (!dq.empty())
    {
        if (r_count % 2 == 0)
        {
            if (dq.size() != 1)
            {
                cout << dq.front() << ",";
            }
            else
            {
                cout << dq.front();
            }
            dq.pop_front();
        }
        else
        {
            if (dq.size() != 1)
            {
                cout << dq.back() << ",";
            }
            else
            {
                cout << dq.back();
            }
            dq.pop_back();
        }
    }
    // if (r_count % 2 == 0)
    // {
    //     for (auto i = dq.begin(); i != dq.end(); i++)
    //     {
    //         if (*i != dq.back())
    //         {
    //             cout << *i << ",";
    //         }
    //         else
    //         {
    //             cout << *i;
    //         }
    //     }
    // }
    // else
    // {
    //     if (!dq.empty())
    //     {
    //         for (auto i = --dq.end(); i != dq.begin(); i--)
    //         {
    //             cout << *i << ",";
    //         }
    //     }
    //     if (!dq.empty())
    //     {
    //         cout << dq.front();
    //     }
    // }
    cout << "]";
    cout << endl;
}
void dqInit()
{
    int n;
    cin >> n;
    char L, R, comma;
    cin >> L;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        if (i != n - 1)
        {
            cin >> comma;
            dq.push_back(number);
        }
        else
        {
            dq.push_back(number);
        }
    }
    cin >> R;
}
void doCommand(string commandLine)
{
    int r_count = 0;
    for (int i = 0; i < commandLine.length(); i++)
    {
        char command = commandLine[i];
        if (command == 'R')
        {
            r_count++;
        }
        else
        {
            if (dq.empty())
            {
                cout << "error" << endl;
                return;
            }
            else
            {
                if (r_count % 2 == 0)
                {
                    dq.pop_front();
                }
                else
                {
                    dq.pop_back();
                }
            }
        }
    }
    Output(r_count);
}
void Solve()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        dq.clear();
        string commandLine;
        cin >> commandLine;
        dqInit();
        doCommand(commandLine);
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