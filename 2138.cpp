#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
string s1;
string s2;
string target;
int ret = INT32_MAX;
bool Check(string &s, int idx)
{
    for (int i = idx - 1; i <= idx; i++)
    {
        if (s[i] != target[i])
        {
            return false;
        }
    }
    return true;
}
void Change(string &s, int idx)
{
    if (idx > 0)
        s[idx - 1] = (s[idx - 1] == '0') ? '1' : '0';
    s[idx]=(s[idx]=='0')? '1':'0';
    if(idx<n-1)
        s[idx+1]=(s[idx+1]=='0') ? '1' : '0';
}
void Bulb(string &s, int idx, int cnt)
{
    if(idx==n-1){
        if(Check(s,idx))
            ret=min(ret,cnt);
        
        Change(s,idx);
        if(Check(s,idx))
            ret=min(ret,cnt+1);
        
        return;
    }
    if(s[idx-1]==target[idx-1])
        Bulb(s,idx+1,cnt);
    
    Change(s,idx);
    if(s[idx-1]==target[idx-1])
        Bulb(s,idx+1,cnt+1);
}
void Solve()
{
    cin >> n >> s1 >> target;
    s2 = s1;
    Bulb(s1, 1, 0);
    Change(s2, 0);
    Bulb(s2, 1, 1);

    if (ret == INT32_MAX)
        cout << -1 << endl;
    else
        cout << ret << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}