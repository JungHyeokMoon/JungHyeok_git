#include <bits/stdc++.h>
using namespace std;
const int MAX=100001;
int N,K;

bool isinside(int hc){
    if(hc<0 || hc>100000)return false;
    return true;
}
bool visited[MAX];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>N>>K; 
    queue<pair<int,int>> q;
    q.push({N,0});
    visited[N]=true;

    while(!q.empty()){
        int hc=q.front().first;
        int ht=q.front().second;
        q.pop();

        //cout<<"hc : "<<hc<<" , "<<"ht : "<<ht<<"\n";

        if(hc==K){
            cout<<ht<<"\n";
            return 0;
        }

        int nc=hc*2;
        if(isinside(nc)&&!visited[nc]){
            q.push({nc,ht});
            visited[nc]=true;
        }

        nc=hc-1;
        if(isinside(nc)&&!visited[nc]){
            q.push({nc,ht+1});
            visited[nc]=true;
        }

        nc=hc+1;
        if(isinside(nc)&&!visited[nc]){
            q.push({nc,ht+1});
            visited[nc]=true;
        }

    }
    

    return 0;
}