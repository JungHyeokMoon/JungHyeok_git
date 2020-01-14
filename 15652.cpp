#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ret;
void n_m(int start,int cnt){
    
    if(cnt==m){        
        for(auto i :ret )cout<<i<<" ";
        cout<<"\n";
        return ;
    }
    
    for(int i=start; i<=n; i++){
        ret.push_back(i);
        n_m(i,cnt+1);
        ret.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;
    n_m(1,0);
    return 0;
}