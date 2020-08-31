#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
set<string> s;
int ret=0;
void Solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        s.insert(temp);
    }

    for(int i=0; i<m; i++){
        string temp;
        cin>>temp;
        if(s.find(temp)!=s.end())
            ret++;
    }

    cout<<ret<<endl;
        
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}