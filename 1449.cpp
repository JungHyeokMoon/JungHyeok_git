#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,l;
vector<int> leak;
void Init(){
    cin>>n>>l;
    leak.resize(n);
    for(auto & i: leak)
        cin>>i;
}
void Solve(){
    sort(leak.begin(), leak.end());
    int ret=1;
    int beforeIdx=0;
    for(int i=1; i<n; i++){
        if(leak[i]-leak[beforeIdx]>l-1){
            ret++;
            beforeIdx=i;
        }
    }
    cout<<ret<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    return 0;
}