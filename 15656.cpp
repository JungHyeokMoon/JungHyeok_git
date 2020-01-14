#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>ret;
int arr[7];
void n_m(int cnt){
    if(cnt==m){
        for(auto i : ret) cout<<i<<" ";
        cout<<"\n";
        return ;
    }
    for(int i=0; i<n ; i++){
        ret.push_back(arr[i]);
        n_m(cnt+1);
        ret.pop_back(); 
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr,arr+n);
    n_m(0);

    return 0;
}