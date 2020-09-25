#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
vector<int> arr;
void Init(){
    cin>>n>>m;
    arr.resize(n);
    for(auto &i : arr)
        cin>>i;
}
void Solve(){
    sort(arr.begin(),arr.end());
    int s=0, e=arr.size()-1;
    int ret=0;
    while(s<e){
        int sum=arr[s]+arr[e];
        if(sum>m)
            e--;
        else if(sum<m)
            s++;
        else{
            ret++;
            s++;
            e--;
        }
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