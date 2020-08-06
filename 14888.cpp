// #pragma warning(disable:4996)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <stack>
// #include <string>
// #include <cmath>
// #include <queue>
// #include <cstdlib>
// #include <map>
// #include <deque>
// using namespace std;
// int n;
// int number[11];
// int op[4];
// int minret = 2100000000;
// int maxret = -2100000000;

// void backtrack(int idx, int ret) {
// 	if (idx == n-1) {
// 		minret = min(ret, minret);
// 		maxret = max(ret, maxret);
// 		return;
// 	}

// 	for (int i = 0; i < 4; i++) {
// 		if (op[i] != 0) {
// 			op[i] --;
// 			int temp = ret;
// 			if (i == 0) {
// 				ret += number[idx+1];
// 				backtrack(idx + 1, ret );
// 				ret = temp;
// 			}
// 			else if (i == 1) {
// 				ret -= number[idx+1];
// 				backtrack(idx + 1, ret);
// 				ret = temp;
// 			}
// 			else if (i == 2) {
// 				ret = ret * number[idx+1];
// 				backtrack(idx + 1, ret);
// 				ret = temp;
// 			}
// 			else {
// 				ret = ret / number[idx+1];
// 				backtrack(idx + 1, ret );
// 				ret = temp;
// 			}
// 			op[i]++;
// 		}
		
// 	}
// }
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		cin >> number[i];
// 	}
// 	for (int i = 0; i < 4; i++)
// 		cin >> op[i];

// 	backtrack(0, number[0]);

// 	cout << maxret << "\n";
// 	cout << minret << "\n";
// 	return 0;
// }
// //커밋용 주석

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> number;
vector<int> Operator;
int MAX=-1e9;
int MIN=1e9;
void Init(){
	cin>>n;
	number.resize(n);
	for(int i=0; i<n; i++)
		cin>>number[i];
	
	Operator.resize(4); //덧셈,뺄셈,곱셈,나눗셈
	for(int i=0; i<4; i++)
		cin>>Operator[i];
}
void dfs(int cnt, int sum){
	if(cnt==n-1){
		//MAX,MIN 계산하고
		MAX=max(MAX,sum);
		MIN=min(MIN,sum);
		return ;
	}

	for(int i=0; i<4; i++){
		if(Operator[i]!=0){
			Operator[i]-=1;
			if(i==0)
				dfs(cnt+1,sum+number[cnt+1]);
			else if(i==1)
				dfs(cnt+1,sum-number[cnt+1]);
			else if(i==2)
				dfs(cnt+1,sum*number[cnt+1]);
			else 
				dfs(cnt+1,sum/number[cnt+1]);
			Operator[i]+=1;
		}
	}
}
void Solve(){
	dfs(0,number[0]);
	cout<<MAX<<endl<<MIN<<endl;
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