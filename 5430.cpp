#include <bits/stdc++.h>
using namespace std;

int t;
char left_bracket;
char right_bracket;
char comma;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int flag = 0;
        int R = 0;
        string P;
        cin >> P; //함수받는거임

        deque<int> dq;

        int n;
        cin >> n;

        cin >> left_bracket;
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
            {
                int num;
                cin >> num;
                dq.push_back(num);
                cin >> comma;
            }
            else
            {
                int num;
                cin >> num;
                dq.push_back(num);
            }
        }
        cin >> right_bracket;
        //숫자입력 다 받고 덱에 집어넣었음

        int len = P.size();

        for (int j = 0; j < len; j++)
        {
            if (P[j] == 'D')
            {
                if (!dq.empty())
                {
                    if (R % 2 == 0)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
                else
                {
                    cout << "error"
                         << "\n";
                    flag = 1;
                    break;
                }
            } //D
            else
            {
                R++;
            }
        }

        //출력 부분
        if (!flag)
        {
            cout << "[";
            if (R % 2 == 0)
            {
                while (!dq.empty())
                {
                    if (dq.size() == 1)
                    {
                        cout << dq.front();
                        dq.pop_front();
                    }
                    else
                    {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                }
            }
            else
            {
                while (!dq.empty())
                {
                    if (dq.size() == 1)
                    {
                        cout << dq.back();
                        dq.pop_back();
                    }
                    else
                    {
                        cout << dq.back() << ",";
                        dq.pop_back();
                    }
                }
            }
            cout << "]"
                 << "\n";
        }
    }

    return 0;
}