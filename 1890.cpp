#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<vector<int>> MAP;
vector<vector<long long>> dp;
void Init(){
    cin>>n;
    MAP.resize(n,vector<int>(n));
    for(auto & i: MAP)
        for(auto &j : i)
            cin>>j;
    
    dp.resize(n,vector<long long>(n,-1));
}

long long Solve(int y, int x){
    if(y==n-1 && x==n-1)
        return 1;
    
    long long &ret=dp[y][x];
    if(ret!=-1)
        return ret;

    ret=0;
    int jump=MAP[y][x];
    if(jump==0)return 0;
    if(y+jump<n)
        ret+=Solve(y+jump,x);
    if(x+jump<n)
        ret+=Solve(y,x+jump);
    
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    cout<<Solve(0,0);
    return 0;
}