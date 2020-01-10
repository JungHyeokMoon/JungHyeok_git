#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int temp=-1000001;
    int flag=0;
    while(scanf("%d",&n)!=EOF){
        if(temp>n){
            flag=1;
        }
        temp=n;
    }
    if(!flag){
        cout<<"Good"<<"\n";
    }
    else{
        cout<<"Bad"<<"\n";
    }

    return 0;
}