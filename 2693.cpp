#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void Solve(){
    int t;
    cin>>t;
    while(t--){
        vector<int> arr(10);
        for(auto & i :arr)
            cin>>i;
        sort(arr.begin(),arr.end());
        cout<<arr[7]<<endl;
        arr.clear();
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