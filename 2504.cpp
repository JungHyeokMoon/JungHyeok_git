#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void Solve()
{
    string str;
    cin >> str;
    stack<char> stk;
    int ret = 0, temp = 1;
    for (int i = 0; i < str.size(); i++)
    {
        char blanket = str[i];
        if (blanket == '(')
        {
            stk.push(blanket);
            temp *= 2;
        }
        else if (blanket == '[')
        {
            stk.push(blanket);
            temp *= 3;
        }
        else if (blanket == ')')
        {
            if (stk.empty() || stk.top() == '[')
            {
                cout << 0 << endl;
                return;
            }
            else
            {
                if (str[i - 1] == '(')
                {
                    ret += temp;
                }
                stk.pop();
                temp /= 2;
            }
        }
        else
        {
            if (stk.empty() || stk.top() == '(')
            {
                cout << 0 << endl;
                return;
            }
            else
            {
                if (str[i - 1] == '[')
                {
                    ret += temp;
                }
                stk.pop();
                temp /= 3;
            }
        }
    }
    if (stk.empty())
        cout << ret << endl;
    else
        cout << 0 << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}