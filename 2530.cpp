#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int A,B,C,D;

void Input(){
    cin>>A>>B>>C>>D;
}
void Solve(){
    int temp=(C+D)/60;
    // cout<<"temp : "<<temp<<endl;
    int second=(C+D)-temp*60;
    // cout<<"second : "<<second<<endl;
    
    int minute=(B+temp)%60;
    // cout<<"minute : "<<minute<<endl;
    temp=(B+temp)/60;
    int hour=(A+temp)%24;
    // cout<<"hour : "<<hour<<endl;
    cout<<hour<<" "<<minute<<" "<<second<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();

    return 0;
}