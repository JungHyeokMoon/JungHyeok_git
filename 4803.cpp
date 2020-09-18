#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
void Print(int cnt,int tree){
    cout<<"Case "<<cnt<<": ";
    if(tree==0)
        cout<<"No trees."<<endl;
    else if(tree==1)
        cout<<"There is one tree."<<endl;
    else
        cout<<"A forest of "<<tree<<" trees."<<endl;
}
// void dfs(int cur,vector<bool> & visited, vector<vector<int>> & adjlist,int &vertex, int & edge){
//     visited[cur]=true;
//     vertex++;

//     for(auto i :adjlist[cur]){
//         edge++;
//         int next=i;
//         if(!visited[next])
//             dfs(next,visited,adjlist,vertex,edge);
//     }
// }
bool dfs(int cur,int before, vector<bool> & visited, vector<vector<int>> & adjlist){
    visited[cur]=true;
    for(auto next : adjlist[cur]){
        if(next==before)continue;
        if(visited[next])return false;
        if(dfs(next,cur,visited,adjlist)==false)return false;
    }
    return true;
}
void Solve(){
    int cnt=1;
    while(cin>>n>>m){
        if(n==0 && m==0)
            return;
        vector<vector<int>> adjlist(n+1);

        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        int tree=0;
        vector<bool> visited(n+1,false);

        for(int i=1; i<=n; i++){
            if(visited[i]==false){
                // int vertex=0, edge=0;
                if(dfs(i,-1,visited,adjlist))tree++;
                // if(vertex-1==edge/2)tree++;
            }
        }
        
        Print(cnt,tree);
        cnt++;
        visited.clear();
        for(int i=1; i<=n; i++)
            adjlist[i].clear();
        
        adjlist.clear();
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