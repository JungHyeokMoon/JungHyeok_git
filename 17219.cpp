#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int n,m;
map<string,string> M;
void Solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string A,B;
        cin>>A>>B;
        M.insert({A,B});
    }

    for(int i=0; i<m; i++){
        string A;
        cin>>A;
        auto it=M.find(A);
        cout<<it->second<<endl;
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