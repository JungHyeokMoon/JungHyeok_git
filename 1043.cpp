#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, t; //사람수, 파티수, 진실을 아는사람의 수
vector<int> knowTrue;
vector<vector<int>> party;
vector<int> parent;
int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}
void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A == B)
        return;
    parent[B] = A;
}
void Init()
{
    cin >> n >> m;
    party.resize(m);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        knowTrue.push_back(num); //진실을 아는사람 입력받기
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int attend;
            cin >> attend;
            party[i].push_back(attend);
        }
    }
}
void Solve()
{
    int ret = m;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    
    for (int i = 0; i < m; i++)
    {
        int A = party[i][0];
        for (int j = 1; j < party[i].size(); j++)
        {
            int B = party[i][j];
            Union(A, B);
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if(!flag)break;
            int A = party[i][j];
            for (int k = 0; k < knowTrue.size(); k++)
            {
                int B = knowTrue[k];
                if (Find(A) == Find(B))
                {
                    flag = false;
                    break;
                }
            }
            
        }
        if(!flag)
            ret--;
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