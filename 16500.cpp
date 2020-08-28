#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string S;
int N;
vector<string> A;
int Slength;
vector<int> cache;
void Init(){
    cin>>S>>N;
    A.resize(N);
    cache.resize(100+1,-1);
    for(int i=0; i<N; i++)
        cin>>A[i];
    
    Slength=S.size();
}
bool Check(int idx){
    if(idx==Slength)
        return true;
    
    int & ret=cache[idx];
    if(ret!=-1)
        return ret;

    ret=0;
    for(int i=0; i<N; i++){
        if(idx+A[i].size()>Slength)continue;
        if(S.find(A[i],idx)==idx)
            ret|=Check(idx+A[i].size());
    }

    return ret;
}
void Solve(){
    cout<<Check(0)<<endl;
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