#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t;
int n;
void dfs(int cur,vector<bool> & visited,vector<vector<int>> &adjlist){
    visited[cur]=true;
    for(auto next:adjlist[cur]){
        if(!visited[next])
            dfs(next,visited,adjlist);
    }
}
void Solve(){
    cin>>t;
    while(t--){
        cin>>n;
        vector<tuple<int,int,int>> military(n);
        for(int i=0; i<n; i++){
            int x,y,r;
            cin>>x>>y>>r;
            military[i]={x,y,r};
        }
        vector<vector<int>> adjlist(n);
        for(int i=0; i<n; i++){
            int hy,hx,hr;
            tie(hy,hx,hr)=military[i];
            for(int j=i+1; j<n; j++){
                int hhy,hhx,hhr;
                tie(hhy,hhx,hhr)=military[j];

                double r=(double)hr+(double)hhr;
                double d=sqrt((hhy-hy)*(hhy-hy)+(hhx-hx)*(hhx-hx));

                if(d<=r){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        vector<bool>visited(n,false);
        int ret=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,visited,adjlist);
                ret++;
            }
        }
        cout<<ret<<endl;
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