#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;

vector<bool> isvisited;
vector<int> ret;
vector<int> adjlist[10001];
int MAX=-987654321;

void Input(){
    cin>>n>>m;
    isvisited.resize(n+1);
    ret.resize(n+1,0);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjlist[b].push_back(a);
        
    }
}

void Solve(){
    for(int i=1; i<=n ;i++){
        fill(isvisited.begin(), isvisited.end(),false);
        
        isvisited[i]=true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int h=q.front();
            ret[i]++;
            q.pop();
            int length =adjlist[h].size();
            for(int j=0; j<length ;j++){
                if(isvisited[adjlist[h][j]])continue;
                isvisited[adjlist[h][j]]=true;
                q.push(adjlist[h][j]);
            }
        }
        MAX=max(ret[i],MAX);
    }
    for(int i=1; i<=n; i++){
        if(ret[i]==MAX){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}