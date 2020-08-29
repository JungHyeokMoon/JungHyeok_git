#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string S;
vector<string> Arr;
int length;
vector<int> dp;
void Init(){
    cin>>S;
    Arr.push_back("pi");
    Arr.push_back("ka");
    Arr.push_back("chu");
    length=S.size();
    dp.resize(length+1,-1);
}
bool foo(string str,int idx){
    if(idx==length)
        return true;
    
    int & result=dp[idx];
    if(result!=-1)
        return result;
    
    result=0;
    for(int i=0; i<3; i++){
        if(idx+Arr[i].size()>length)continue;
        if(str+Arr[i]==S.substr(0,idx+Arr[i].size()))
            result|=foo(str+Arr[i],idx+Arr[i].size());
    }
    return result;
}
void Solve(){
    if(foo("",0))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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