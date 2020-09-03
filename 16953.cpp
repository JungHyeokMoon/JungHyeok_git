#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long A,B;
vector<bool> visited;
void Init(){
    cin>>A>>B;
    visited.resize(1000000000+1,false);
}
long long Operation(long long number, int idx){
    if(idx==0)
        return number*2;
    else if(idx==1)
       return  number*10+1;
}
bool isInside(long long N){
    if(1<=N && N<=1000000000)
        return true;
    else
        return false;
}
void Solve(){
    queue<pair<long long,long long>> q;
    visited[A]=true;
    q.push({A,0});
    while(!q.empty()){
        auto cur=q.front();
        long long h=cur.first;
        long long hCount=cur.second;
        // cout<<h<<" "<<hCount<<endl;
        q.pop();

        if(h==B){
            cout<<hCount+1<<endl;
            return ;
        }
        for(int i=0; i<2; i++){
            long long nN=Operation(h,i);
            // cout<<"nN: "<<nN<<endl;
            if(!isInside(nN))
                continue;
            if(visited[nN])
                continue;
            
            q.push({nN,hCount+1});
            visited[nN]=true;
        }
    }

    cout<<-1<<endl;
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