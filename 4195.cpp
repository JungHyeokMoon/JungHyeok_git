#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t;
vector<int> parent;
vector<int> cnt;
int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}
void Merge(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if(u!=v){
        parent[v] = u;
        cnt[u]+=cnt[v];
    }
    
}
void Solve()
{
    parent.resize(200001);
    cnt.resize(200001);
    cin >> t;
    while (t--)
    {
        for(int i=0; i<=200000; i++){
            parent[i]=i;
            cnt[i]=0;
        }
        
        int f;
        cin >> f;
        map<string, int> m;

        int idx = 0;
        for (int i = 0; i < f; i++)
        {
            string A, B;
            cin >> A >> B;
            int idx1,idx2;
            if(m.find(A)==m.end()){
                m[A]=idx;
                idx1=idx++;
                cnt[idx1]++;
            }else
                idx1=m[A];

            if(m.find(B)==m.end()){
                m[B]=idx;
                idx2=idx++;
                cnt[idx2]++;
            }else
                idx2=m[B];
            
            if(idx1<idx2)
                swap(idx1,idx2);
            
            Merge(idx1,idx2);
            cout<<cnt[parent[idx1]]<<endl;
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