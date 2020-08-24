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

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	std::cout.tie(NULL);

// 	cin >> n;
// 	vector<int> input(n , 0);
// 	vector<int> dp(n , 1);

// 	for (int i = 0; i < n; i++) {
// 		cin >> input[i];
// 	}
// 	int ret = 1;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < i; j++) {
// 			if (input[j] < input[i]) {
// 				dp[i] = max(dp[i], dp[j] + 1);
// 			}
// 		}
// 		ret = max(ret, dp[i]);
// 	}

// 	cout << ret << endl;

// 	return 0;

// }

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
	dp.resize(n+1,0);
	dp[1]=1;
}
int TopDown(int idx){
	int &ret=dp[idx];
	if(ret!=0)return ret;

	ret=1;

	for(int i=idx-1; i>0; i--)
		if(arr[i]<arr[idx])
			ret=max(ret,TopDown(i)+1);
	
	return ret;
}
void Solve(){
	int res=0;
	for(int i=1; i<=n ;i++)
		res=max(res,TopDown(i));
	
	cout<<res<<endl;
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