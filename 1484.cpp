#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int g;
void Solve(){
    cin>>g;
    int cur=2, prev=1;
    vector<int> ret;
    while(prev<cur){
        int weight=cur*cur-prev*prev;
        // cout<<prev<<" "<<cur<<endl;
        if(weight>g){
            prev++;
        }
        else if(weight==g){
            ret.push_back(cur);
            cur++;
        }
        else cur++;
        if(cur==100000)break;   
    }
    if(ret.size()==0)
        cout<<-1<<endl;
    else{
        for(auto i : ret)
            cout<<i<<endl;
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