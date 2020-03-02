#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int T;
int N;
map<string, int> m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        m.clear();
        cin >> N;
        int ret = 1;
        for (int i = 0; i < N; i++)
        {
            string cloth, kind;
            cin >> cloth >> kind;
            m[kind]++;
            
        }
        for (auto i : m)
            {
                ret *= (i.second + 1);
            }
            ret -= 1;
            cout << ret << endl;
    }
}
