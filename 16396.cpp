#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<bool> visited;
void Init(){
    visited.resize(10000+1,false);
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        for(int j=x; j<y; j++)
            visited[j]=true;
    }
}
void Solve(){
    int cnt=0;
    for(int i=1; i<=10000; i++){
        if(visited[i])cnt++;
    }
    cout<<cnt<<endl;
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