// #include <iostream>
// #include <algorithm>
// using namespace std;

// int dp[1000 + 1];//2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� �� �� ���̳������̺����ִ�. dp[n]=dp[n-1]+dp[n-2];

// int main(){
// 	int n;
// 	scanf("%d" ,&n);

// 	dp[0] = 1; //2*0 ��ä��¹���� ���������λ����ϰ� �ϳ����ִٰ� �����ؾ���... 
// 	dp[1] = 1;
// 	for (int i = 2; i <= n; i++) {
// 		dp[i] = dp[i - 1] + dp[i - 2];
// 		dp[i] = dp[i] % 10007;
// 	}

// 	printf("%d\n", dp[n]);

// 	return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
#define MOD 10007
using namespace std;
int n;
vector<int> dp;
void Init(){
	cin>>n;
	dp.resize(n+1,-1);
	dp[1]=1 , dp[2]=2;
}
int Tiling(int n){
	if(dp[n]!=-1)
		return dp[n];

	dp[n]=(Tiling(n-1)%MOD+Tiling(n-2)%MOD)%MOD;
	return dp[n];
}
void Solve(){
	cout<<Tiling(n)<<endl;
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