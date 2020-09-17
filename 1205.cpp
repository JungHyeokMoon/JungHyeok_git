#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,score,p;
vector<int> ranking;
void Init(){
    cin>>n>>score>>p;
    ranking.resize(n);
    for(auto & i :ranking)
        cin>>i;
}
bool Compare(int a, int b){
    return a>=b;
}
void Solve(){
    if (n==0){
        cout<<1<<endl;
        return ;
    }
    // int idx=lower_bound(ranking.begin(),ranking.end(),score,Compare)-ranking.begin();
    // if(idx==n-1){
    //     if(n==p &&score==ranking[n-1])
    //         cout<<-1<<endl;
    //     else
    //         cout<<idx+1<<endl;
    // }
    // else
    //     cout<<idx+1<<endl;
    int rank=1;
    if(n==p && ranking[n-1]>=score){
        cout<<-1<<endl;
        return ;
    }
    else{
        for(auto i : ranking){
            if(i>score)
                rank++;
        }
    }
    cout<<rank<<endl;
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