#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int Arr[100000];
void Input(){
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>Arr[i];
    }
}
void Solve(){
    sort(Arr,Arr+n);
    // for(int i=0; i<n; i++){
    //     cout<<Arr[i]<<" ";
    // }
    // cout<<endl;
    int temp=Arr[0];
    cout<<Arr[0]<<" ";
    for(int i=1; i<n; i++){
        if(temp!=Arr[i]){
            cout<<Arr[i]<<" ";
        }
        temp=Arr[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}