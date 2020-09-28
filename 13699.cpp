#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<long long> dp;
int n;
void Solve(){
    cin>>n;
    dp.resize(n+1,0);
    dp[0]=1;
    for(int i=1; i<=n; i++){

        for(int j=0; j<=i-1; j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    cout<<dp[n]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}