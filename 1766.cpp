#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<int> indegree;
vector<vector<int>> adjlist;
void Init(){
    cin>>n>>m;
    adjlist.resize(n+1);
    indegree.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        indegree[b]++;
    }
}
void Solve(){
    priority_queue<int> pq;
    for(int i=1; i<=n; i++)
        if(indegree[i]==0)pq.push(-i);
    
    while(!pq.empty()){
        int cur=-pq.top();
        pq.pop();

        cout<<cur<<" ";

        for(auto next:adjlist[cur]){
            if(--indegree[next]==0) pq.push(-next);
        }
    }
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