#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int k=2*n-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i-1; j++){
            cout<<" ";
        }//공백출력
        for(int j=1; j<=k; j++){
            cout<<"*";  
        }//별출력
        cout<<"\n";
        k=k-2;
    }
}