#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int T;
void Solve()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int k;
        cin >> k;
        map<int, int> m;
        for (int i = 0; i < k; i++)
        {
            char ch;
            int num;
            cin >> ch >> num;
            if (ch == 'I')
            {
                m[num]++;
            }
            else
            {   
                if(m.empty())
                    continue;
                if (num == 1) //최대값삭제
                {
                    auto it=m.rbegin();
                    if(it->second==1)
                        m.erase(it->first);
                    else
                        m[it->first]--;
                }
                else if (num == -1) //최소값삭제
                {
                    auto it=m.begin();
                    if(it->second==1)
                        m.erase(it->first);
                    else
                        m[it->first]--;
                }
            }
        }

        if(m.empty())
            cout<<"EMPTY"<<endl;
        else{
            auto it=m.begin();
            auto rit=m.rbegin();
            cout<<rit->first<<" "<<it->first<<endl;
        }
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