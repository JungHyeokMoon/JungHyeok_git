#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<string> arr;

void Init(){
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
}
void Solve(){
    regex reg("(((10)(0+)(1+)|01)+)");
    for(auto i :arr){
        if(regex_match(i,reg))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
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