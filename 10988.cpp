#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string input;
bool Check(){
    int s=0, e=input.size()-1;
    while(s<e){
        if(input[s++]!=input[e--])return false;
    }
    return true;
}
void Solve(){
    cin>>input;
    if(Check())cout<<1<<endl;
    else cout<<0<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}