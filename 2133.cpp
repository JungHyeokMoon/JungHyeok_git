#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<int> dp;
void Init()
{
    cin>>n;
    dp.resize(n+1);
    dp[0]=1;
}
void Solve(){
    if(n%2!=0){
        cout<<0<<endl;
        return ;
    }
    dp[2]=3;
    for(int i=4; i<=n; i+=2){
        dp[i]+=dp[i-2]*3;
        for(int j=4; j<=i; j=j+2)
            dp[i]+=dp[i-j]*2;
    }
    cout<<dp[n]<<endl;

    
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