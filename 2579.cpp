// #pragma warning(disable:4996)
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <string.h>
// #include <map>
// using namespace std;


// int n;
// int dp[301];
// int stair[301];

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	std::cout.tie(NULL);

// 	cin >> n;
	

// 	for (int i = 1; i <= n; i++)
// 		cin >> stair[i];

// 	dp[1] = stair[1];
// 	dp[2] = stair[1] + stair[2];
// 	for (int i = 3; i <= n; i++) {
// 		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
// 	}
// 	cout << dp[n] << endl;
// 	return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> stair;
vector<vector<int>> dp;
void Init(){
	cin>>n;
	stair.resize(n+1);
	for(int i=1; i<=n; i++)
		cin>>stair[i];

	dp.resize(301,vector<int>(3,-1)); //dp[i][j] = 연속으로 j개의 계단을 밟고 i번째 계단을 올라왔을때 얻을수있는 최대점수
	dp[1][1]=stair[1];
	dp[1][2]=0; 
}
int Solve(int i, int j){
	if(i<=0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];

	if(j==2)
		dp[i][j]=max(dp[i][j],stair[i]+Solve(i-1,1));
	if(j==1){
		dp[i][j]=max(dp[i][j],stair[i]+Solve(i-2,2));
		dp[i][j]=max(dp[i][j],stair[i]+Solve(i-2,1));
	}
	return dp[i][j];
}
void Solve(){
	cout<<max(Solve(n,1),Solve(n,2))<<endl;
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