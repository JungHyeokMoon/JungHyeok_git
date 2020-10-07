#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void Solve(){
    string A,B;
    cin>>A>>B;
    int lengthOfA=A.size();
    while(B.size()>=lengthOfA){

        if(A==B){
            cout<<1<<endl;
            return;
        }
        char c=B.back();
        B.pop_back();
        if(c=='B')
            reverse(B.begin(),B.end());
    }
    cout<<0<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}