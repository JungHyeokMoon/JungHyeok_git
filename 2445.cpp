#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n; 
    
    int up=2*n-2;
    for(int i=1; i<=2*n-1; i++){
        if(i==n){
            for(int j=1; j<=2*n; j++){
                cout<<"*";
            }
            up=up+2;
        }//중앙
        else if(i<n){
            for(int j=1; j<=i; j++){
                cout<<"*";
            }
            for(int j=1; j<=up ; j++){
                cout<<" ";
            }
            for(int j=1; j<=i ;j++){
                cout<<"*";
            }
            up=up-2;
        }//윗부분
        else{
            for(int j=2*n-i; j>0; j--){
                cout<<"*";
            }
            for(int j=1; j<=up ; j++){
                cout<<" ";
            }
            for(int j=2*n-i; j>0; j--){
                cout<<"*";
            }
            up=up+2; 
        }//아랫부분
        cout<<"\n";
    }
    return 0;
}