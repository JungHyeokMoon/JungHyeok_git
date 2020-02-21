#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int Arr[1000000];
int n;

void Input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>Arr[i];
    }
}
bool compare(const int & a ,const int & b){
    return a>b;
}
void Solve(){
    sort(Arr,Arr+n,compare);
    for(int i=0; i<n; i++){
        cout<<Arr[i]<<endl;
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