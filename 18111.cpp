#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, b;
vector<vector<int>> MAP;
pair<int, int> ret = {INT32_MAX, 0};
void Init()
{
    cin >> n >> m >> b;
    MAP.resize(n, vector<int>(m));
    for (auto &i : MAP)
        for (auto &j : i)
            cin >> j;

}
void Leveling(int h, int block)
{
    
    int Time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(MAP[i][j]>h){
                Time+=(MAP[i][j]-h)*2;
                block+=(MAP[i][j]-h);
            }
            else if(MAP[i][j]<h){
                    Time+=(h-MAP[i][j]);
                    block-=(h-MAP[i][j]);
            }
        }
    }
    if(block<0)return ;
    if (ret.first > Time)
    {
        ret.first = Time;
        ret.second = h;
    }
    else if (ret.first == Time)
        ret.second = h;
}
void Solve()
{
    for (int i=0; i<=256; i++)
        Leveling(i, b);
    cout << ret.first << " " << ret.second << endl;
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