#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> arr;
vector<int> dp;
void Init(){
    cin>>n;
    arr.resize(n+1);
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    
    dp.resize(n+1,-1);
    dp[1]=arr[1];
}
void Solve(){
    for(int i=2; i<=n; i++)
        dp[i]=max(0,dp[i-1])+arr[i];
    cout<<*max_element(dp.begin()+1,dp.begin()+n+1)<<endl;
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