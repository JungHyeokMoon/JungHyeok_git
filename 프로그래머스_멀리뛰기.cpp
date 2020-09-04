#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
long long solution(int n) {
    long long answer = 0;
    dp.resize(n+1,-1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n ; i++)
        dp[i]=(dp[i-1]%1234567+dp[i-2]%1234567)%1234567;
    return dp[n];
}
int main()
{
    cout<<solution(3)<<endl;
    return 0;
}