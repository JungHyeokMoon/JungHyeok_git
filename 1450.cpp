// #include <bits/stdc++.h>	
// #define endl "\n"	
// using namespace std;
// int n,c;
// vector<int> napsack;
// vector<bool> check;
// int cnt=0;
// void Input(){
//     cin>>n>>c;
//     napsack.resize(n);
//     check.resize(n,false);
//     for(int i=0; i<n; i++)cin>>napsack[i];
// }
// void Pack(int idx,long long storage){
//     if(0<storage &&storage<=c){
//         cnt++;
//     }
//     if(idx==n){
//         return ;
//     }
    

//     for(int i=idx; i<n; i++){
//         if(!check[i]){
//             check[i]=true;
//             storage+=napsack[i];
//             Pack(i+1,storage);
//             storage-=napsack[i];
//             check[i]=false;
//         }
//     }
// }
// void Solve(){
//     Pack(0,0);
//     cout<<cnt+1<<endl;
// }
// int main(){	
//     ios_base::sync_with_stdio(0);	
//     cin.tie(0);	
//     cout.tie(0);
//     Input();
//     Solve();
//     return 0;
// } //당연히 시간초과나오는 코드 n이 2^30이기때문에 

#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n,c;
vector<int> napsack;
int cnt=0;
vector<int> v1,v2;
void Input(){
    cin>>n>>c;
    napsack.resize(n);
    for(int i=0; i<n; i++)cin>>napsack[i];
}
void Pack(int s,int e,int storage,vector<int> & v){
    if(storage>c)return ;
    if(s>e){
        v.push_back(storage);
        return ;
        
    }
    Pack(s+1,e,storage,v);
    Pack(s+1,e,storage+napsack[s],v);
}
void Solve(){
    Pack(0,(n/2)-1,0,v1);
    Pack((n/2),n-1,0,v2);

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    int length1=v1.size();
    int length2=v2.size();

    for(int i=0; i<length1; i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"v2 : "<<endl;
    for(int i=0; i<length2; i++){
        cout<<v2[i]<<" ";
    }
    // cout<<length1<<" "<<length2<<endl;
    int e=length2-1;
    for(int i=0; i<length1; i++){
        // for(int j=0; j<length2; j++){
        //     if(v1[i]+v2[j]>c)break;
        //     cnt++;
        // }
        while(e>=0 && v1[i]+v2[e]>c) e--;
        cnt+=e+1;
    }
    // cout<<cnt<<endl;
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Input();
    Solve();
    return 0;
} //두개로나눠서 어떻게 잘합칠지를 생각해야함



// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int n, c, ans, a[33];
// vector<int> v1, v2;

// void dfs(int s, int e, int sum, vector<int>& v) {
// 	if (sum > c) return;
// 	if (s > e) return v.push_back(sum);
// 	dfs(s + 1, e, sum, v);
// 	dfs(s + 1, e, sum + a[s], v);
// }

// int main() {
// 	scanf("%d %d", &n, &c);
// 	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

// 	dfs(0, n / 2 - 1, 0, v1); sort(v1.begin(), v1.end());
// 	dfs(n / 2, n - 1, 0, v2); sort(v2.begin(), v2.end());

//     int length1=v1.size();
//     int length2=v2.size();

//     for(int i=0; i<length1; i++){
//         cout<<v1[i]<<" ";
//     }
//     cout<<endl<<endl;
//     cout<<"v2 : "<<endl;
//     for(int i=0; i<length2; i++){
//         cout<<v2[i]<<" ";
//     }
	
// 	// int e = v2.size() - 1;
// 	// for (int s = 0; s < v1.size(); s++) {
// 	// 	while (e >= 0 && v1[s] + v2[e] > c) e--;
// 	// 	ans += e + 1;
// 	// }
// 	// printf("%d", ans);

// 	return 0;
// }
