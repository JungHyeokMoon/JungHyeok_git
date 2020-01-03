#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int num;
    cin>>num;

    int cnt=0;
    for(int i=0 ; i<n; i++){
        if(v[i]==num)cnt++;
    }

    cout<<cnt<<"\n";
    
    return 0;
}