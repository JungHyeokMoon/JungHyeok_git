#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int Number[4];
int clockNumber = 1e9;
int myClockNumber;
// int iter = 0;
void Input()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> Number[i];
    }
}
int makeClockNumber()
{

    for (int i = 0; i < 4; i++)
    {
        int ret = 0;
        int iter = 3;
        for (int j = i; j < i + 4; j++)
        {
            int k = j % 4;
            ret += Number[k] * pow(10, iter--);
        }
        clockNumber = min(clockNumber, ret);
    }
    // cout << clockNumber << endl;
    return clockNumber;
}
set<int> s;
void Solve()
{
    myClockNumber = makeClockNumber();
    int iter = 1;
    for (int i = 1111; i <= 9999; i++)
    {
        clockNumber = 1e9;
        int k = i;
        int idx = 0;
        bool flag = true;
        while (k != 0)
        {
            int inputnum = k % 10;
            if (!inputnum)
            {
                flag = false;
                break;
            }
            Number[idx++] = k % 10;
            k = k / 10;
        }
        if (!flag)
            continue;
        int temp = makeClockNumber();
        if (s.find(temp) == s.end())
        {
            // cout << temp << endl;
            s.insert(temp);
        }
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        if (*it == myClockNumber)
        {
            cout << iter << endl;
            break;
        }
        iter++;
    }
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
