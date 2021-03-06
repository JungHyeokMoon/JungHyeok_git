// #pragma warning(disable:4996)
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <string.h>
// #include <math.h>
// using namespace std;
// int n, k;
// const int MAX_N = 101;
// const int MAX_K = 10001;
// int coin[MAX_N];
// int dp[MAX_K];
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> n >> k;
// 	dp[0] = 1; // 0원을 만드는경우의수 1가지
// 	for (int i = 1; i <= n; i++)
// 		cin >> coin[i];

// 	for (int i = 1; i <= n; i++) {
// 		for (int j = coin[i]; j <= k; j++) {
// 			dp[j] += dp[j - coin[i]];
// 		}
// 	}// j 가왜 coin[i]부터인가는 1원을만들때는 2원을사용못하니깐
// 	cout << dp[k] << endl;
// 	return 0;
// }




#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,k;
vector<int> arr;
vector<int> dp;
void Init(){
	cin>>n>>k;
	arr.resize(n+1);
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	dp.resize(k+1,0);
}
void Solve(){
	dp[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=arr[i]; j<=k; j++){
			dp[j]=dp[j]+dp[j-arr[i]];
		}
	}
	cout<<dp[k]<<endl;
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