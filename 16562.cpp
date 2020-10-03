#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,k;
vector<int> friendMoney;
vector<vector<int>> adjlist;
vector<bool> visited;
vector<vector<int>> friendSet;
void Init(){
    cin>>n>>m>>k;
    friendMoney.resize(n+1);
    adjlist.resize(n+1);
    visited.resize(n+1,false);
    for(int i=1; i<=n; i++)
        cin>>friendMoney[i];

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    
}
void dfs(int cur,vector<int> & temp){
    visited[cur]=true;
    temp.push_back(cur);
    for(auto next: adjlist[cur]){
        if(!visited[next])
            dfs(next,temp);
    }
}
void Solve(){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(i,temp);
            friendSet.push_back(temp);
        }
    }
    int ret=0;
    for(int i=0; i<friendSet.size(); i++){
        int minMoney=INT32_MAX;
        for(int j=0; j<friendSet[i].size(); j++)
            minMoney=min(minMoney,friendMoney[friendSet[i][j]]);
        ret+=minMoney;
    }

    
    if(ret<=k)
        cout<<ret<<endl;
    else
        cout<<"Oh no"<<endl;
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