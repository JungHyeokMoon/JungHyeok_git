#include <bits/stdc++.h>
using namespace std;
int t;
int h,w,n; //층 , 방갯수 ,몇번째 손님

void Solve(){
    cin>>t;
    for(int i=0; i<t ; i++){
        cin>>h>>w>>n;
        n=n-1;
        int x=(n%h)+1;
        int y=(n/h)+1;
        if(y>=10){
            cout<<x<<y<<"\n";
        }
        else{
            cout<<x<<"0"<<y<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solve();
    return 0;
}