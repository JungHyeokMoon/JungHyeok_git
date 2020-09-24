#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,t,g;
vector<int> dist;
void Init(){
    cin>>n>>t>>g;
    dist.resize(100000,-1);
}
int nextNumber(int number,int idx){
    if(idx==0)
        return number+1>=100000 ? -1 : number+1;
    else{
        if(number==0)
            return 0;
        if(number*2>=100000)
            return -1;
        else{
            number*=2;
            int temp=number;
            int cnt=0;
            while(1){
                if(temp/10==0)break;
                temp/=10;
                cnt++;
            }
            int tenPow=1;
            for(int i=0; i<cnt; i++)
                tenPow*=10;
            
            int ret=number-tenPow;
            return ret>=100000? -1: ret;
        }
    }
}
void Solve(){
    dist[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0; i<2; i++){
            int next=nextNumber(cur,i);
            if(next==-1)continue;
            if(dist[next]!=-1)continue;
            q.push(next);
            dist[next]=dist[cur]+1;
        }
    }
    if(0<=dist[g] && dist[g]<=t)
        cout<<dist[g]<<endl;
    else
        cout<<"ANG"<<endl;
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