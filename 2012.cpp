#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> v;
long long ret=0;
void Input(){
    cin>>n;
    v.resize(n);
    for(int i=0; i<n ; i++){
        cin>>v[i];
    }
}
void Solve(){
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        ret+=abs(v[i]-(i+1));
    }
    cout<<ret<<endl;
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