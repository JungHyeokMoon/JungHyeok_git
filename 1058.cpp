#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
int ret = 0;
vector<vector<int>> adjlist;
const int INF = 1000000000;
void Init()
{
    cin >> n;
    adjlist.resize(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
            if (temp[j] == 'Y')
                adjlist[i].push_back(j);
    }

}
void Solve()
{
    for(int i=0; i<n; i++){
        vector<int> dist(n,-1);
        dist[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            for(auto next: adjlist[cur]){
                if(dist[next]!=-1)continue;
                dist[next]=dist[cur]+1;
                q.push(next);
            }
        }
        int cnt=0;
        for(int j=0; j<n; j++){
            if(0<dist[j] && dist[j]<=2){
                cnt++;
            }
        }
        ret=max(ret,cnt);
    }
    cout<<ret<<endl;
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