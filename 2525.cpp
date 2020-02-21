#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int A,B,C;
void Input(){
    cin>>A>>B>>C;
}
void Solve(){
    if(!((B+C)/60)){
        cout<<A<<" "<<B+C<<endl;
    }else{
        int temp=(B+C)/60;
        int minute=(B+C)-60*temp;
        int hour=A+temp;
        cout<<hour%24<<" "<<minute<<endl;
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