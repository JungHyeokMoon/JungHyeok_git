#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int solution(int n) {
    dp.resize(n+1,-1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]=(dp[i-2]%1000000007+dp[i-1]%1000000007)%1000000007;
    }
    return dp[n];
}

int main(){
    cout<<solution(4);
    return 0;
}