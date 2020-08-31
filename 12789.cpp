#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> Arr;
void Init()
{
    cin >> n;
    Arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> Arr[i];
}
void Solve()
{
    stack<int> stk;
    queue<int> q;
    int cnt = 1;
    for (auto number : Arr)
    {
        if (number == cnt)
        {
            q.push(number);
            cnt++;
            if(!stk.empty()){
                while(stk.top()==cnt ){
                    q.push(stk.top());
                    stk.pop();
                    cnt++;
                    if(stk.empty())
                        break;
                }
            }
        }
        else if (cnt < number)
        {
            if (stk.empty())
                stk.push(number);
            else
            {
                if (number < stk.top())
                    stk.push(number);
                else
                {
                    cout << "Sad" << endl;
                    return;
                }
            }
        }
    }
    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }
    if (q.size() == n)
        cout << "Nice" << endl;
    else
        cout << "Sad" << endl;
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