#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int k=1;

    for(int i=0; i<n-1; i++){
        for(int j=n-i; j>1; j--){
            cout<<" ";
        }
        for(int j=0; j<k; j++){
            cout<<"*";
        }
        k=k+2;
        cout<<"\n";
    }
    for(int i=0; i<2*n-1; i++){
        cout<<"*";
    } // 중앙
    cout<<"\n";
    k=2*n-3;
    for(int i=0; i<n-1; i++){
        for(int j=-1; j<=i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<k; j++){
            cout<<"*";
        }
        cout<<"\n";
        k=k-2;
    }
    return 0; 
}