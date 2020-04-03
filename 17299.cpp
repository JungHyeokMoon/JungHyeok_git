#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<int> arr;
// map<int,int> m;
int m[1000001];
vector<int> f;
vector<int> ret;
void Input(){
    cin>>n;
    arr.resize(n);
    ret.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    f.resize(n);

    for(int i=0; i<n; i++){
        f[i]=m[arr[i]];
    }
}
void Solve(){
    stack<pair<int,int>> stk; //f[i], arr[i]
    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && f[i]>=stk.top().first){
            stk.pop();
        }
        if(stk.empty()){
            ret[i]=-1;
        }
        else{
            ret[i]=stk.top().second;
        }
        stk.push({f[i],arr[i]});
    }
    for(int i=0; i<n; i++){
        cout<<ret[i]<<" ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}