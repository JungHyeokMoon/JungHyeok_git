#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,k;
vector<int> arr;
void Init(){
    cin>>n>>k;
    arr.resize(n);
    for(auto & i :arr)
        cin>>i;
}
void Solve(){
    
    int sum=0;
    for(int i=0; i<k; i++)
        sum+=arr[i];
    int l=0, r=k;
    int ret=sum;
    while(1){
        if(r==n)break;
        sum=sum-arr[l++]+arr[r++];
        ret=max(ret,sum);
    }
    cout<<ret<<endl;
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