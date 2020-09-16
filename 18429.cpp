#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,k;
vector<pair<int,int>> kit;
int ret=0;
void Init(){
    cin>>n>>k;
    // kit.resize(n);
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        kit.push_back({i,num});
    }
}
void dfs(int idx,int curWeight){
    if(idx==n){
        ret++;
        return ;
    }
    curWeight-=k;
    curWeight+=kit[idx].second;
    if(curWeight<500)
        return;
    
    dfs(idx+1,curWeight);
}
void Solve(){
    do{
        dfs(0,500);
    }while(next_permutation(kit.begin(),kit.end()));
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