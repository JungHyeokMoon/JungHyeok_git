#include <bits/stdc++.h>
using namespace std;
const int MAX=100001;
int N,K;

bool isinside(int hc){
    if(hc<0 || hc>100000)return false;
    return true;
}
bool visited[MAX];
int parent[MAX];
vector<int >ret;
void print(int hc){
    if(parent[hc]==-1)return ;
    ret.push_back(parent[hc]);
    print(parent[hc]);
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    fill(parent,parent+MAX,-1);
    cin>>N>>K;

    visited[N]=true;
    queue<pair<int,int>>q;
    q.push({N,0});

    while(!q.empty()){
        int hc=q.front().first;
        int ht=q.front().second;

        q.pop();
        if(hc==K){
            cout<<ht<<"\n";
            
            ret.push_back(hc);
           
            print(hc);
            reverse(ret.begin(),ret.end());
            for(auto i : ret)cout<<i<<" ";
            return 0;
        }
        int nc=hc*2;
        if(isinside(nc)&&!visited[nc]){
            visited[nc]=true;
            q.push({nc,ht+1});
            parent[nc]=hc;
        }

        nc=hc-1;
        if(isinside(nc)&&!visited[nc]){
            visited[nc]=true;
            q.push({nc,ht+1});
            parent[nc]=hc;
        }

        nc=hc+1;
        if(isinside(nc)&&!visited[nc]){
            visited[nc]=true;
            q.push({nc,ht+1});
            parent[nc]=hc;
        }
    }

    return 0;

}