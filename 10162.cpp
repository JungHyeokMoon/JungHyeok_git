#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int t;
void Input(){
    cin>>t; //초로 주어짐
}
void Solve(){
    //A는 300초 , B는 60초, C는 10초
    if(t%10!=0){
        cout<<-1<<endl;
        return ;
    }
    cout<<(t/300)<<" ";
    t=t%300;
    cout<<(t/60)<<" ";
    t=t%60;
    cout<<(t/10)<<" ";
    return ;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}