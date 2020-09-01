#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int S=0;
int M;
void Solve(){
    cin>>M;
    for(int i=0; i<M; i++){
        string cmd;
        cin>>cmd;

        if(cmd=="add"){
            int num;
            cin>>num;
            num--;
            S=S|(1<<num);
        }else if(cmd=="remove"){
            int num;
            cin>>num;
            num--;
            S=S & ~(1<<num);
        }else if(cmd=="check"){
            int num;
            cin>>num;
            num--;
            if( S & (1<<num))cout<<1<<endl;
            else cout<<0<<endl;
        }else if(cmd=="toggle"){
            int num;
            cin>>num;
            num--;
            S=S^(1<<num);
        }else if(cmd=="all"){
            S=(1<<20)-1;
        }else{
            S=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}