#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n;
vector<int> arr;
set<int> S;


void Input(){
    cin>>n;
    arr.resize(n);
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
}
void Make_PartialSet(int idx,int sum){
    if(idx==n){
        return ;
    }
    sum+=arr[idx];
    S.insert(sum);
    Make_PartialSet(idx+1,sum);
    Make_PartialSet(idx+1,sum-arr[idx]);
}
void Solve(){
    Make_PartialSet(0,0);
    set<int>::iterator it=S.begin();
    if(*it!=1){
        cout<<1<<endl;
    }
    else{
        int prev=*it;
        it++;
        // if(it==S.end()){
        //     cout<<2<<endl;
        // }
        bool flag=false;
        int h;
        for(; it!=S.end(); it++){
            h=*it;
            if(h-prev>1){
                cout<<prev+1<<endl;
                flag=true;
                break;
            }
            prev=*it;
        }
        if(!flag){
            cout<<prev+1<<endl;
        }
    }
    // for(set<int>::iterator it=S.begin(); it!=S.end(); it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Input();
    Solve();
    return 0;
}