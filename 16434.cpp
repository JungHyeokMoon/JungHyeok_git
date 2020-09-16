#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, atk;
long long ret = -1;
struct Dungeon
{
    int type, a, h;
};
vector<Dungeon> v;
void Init()
{
    cin >> n >> atk;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].type >> v[i].a >> v[i].h;
}
bool canAdventure(long long mid)
{
    long long curHp = mid;
    long long curAtk = atk;
    for (int i = 0; i < n; i++)
    {
        if (v[i].type == 1)
        {
            if ((v[i].h - 1) / curAtk > (curHp - 1) / v[i].a)
                return false;
            curHp -= (v[i].h - 1) / curAtk * v[i].a;
        }
        else
        {
            curAtk += v[i].a;
            curHp = min(curHp + v[i].h, mid);
        }
    }
    return true;
}

void Solve()
{
    long long left = 1;
    long long right = 1e18;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (canAdventure(mid))
        {
            ret = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ret << endl;
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

