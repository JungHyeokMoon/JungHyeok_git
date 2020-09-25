#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int> arr;
void Init()
{
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;
}
void Solve()
{
    int ret = 0;
    sort(arr.begin(), arr.end());
    // for(auto i :arr)
    //     cout<<i<<" ";
    // cout<<endl;
    for(int i=0; i<n;i++){
        int temp=1;
        for(int j=1; j<5 && i+j<n; j++)
            if(arr[i+j]<arr[i]+5)temp++;
        ret=max(ret,temp);
    }
    cout<<5-ret<<endl;
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