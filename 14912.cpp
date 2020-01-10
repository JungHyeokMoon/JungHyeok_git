#include <bits/stdc++.h>
using namespace std;

int n;
int digit;
int ret=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>digit;

    for(int i=1; i<=n; i++){
        int temp=i;
        while(temp!=0){
            if(temp%10==digit){
                ret++;
            }
            temp=temp/10;
        }
    }
    cout<<ret<<"\n";
    return 0;
}