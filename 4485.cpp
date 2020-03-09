#include <bits/stdc++.h>
using namespace std;
int n;
int arr[126][126];
int dist[126][126];
#define endl "\n"
#define MAX 987654321
typedef pair<int,pair<int,int>> piii;
const int dy[4]={0,-1,0,1};
const int dx[4]={-1,0,1,0};
bool isinside(int y, int x){
    if(y>=0 && y<n &&x>=0 && x<n){
        return true;
    }
    return false;
}

void distInit(){
    for(int i=0; i<n; i++){
        fill(dist[i],dist[i]+n,MAX);
    }
}


void Solve(){
    int i=1;
    while(1){
        cin>>n;
        if(!n){
            break;
        }
        distInit();
        
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin>>arr[j][k];
            }
        }
        
        
        priority_queue<piii,vector<piii>,greater<piii>>pq;
        pq.push({arr[0][0],{0,0}});
        dist[0][0]=arr[0][0];
        while(!pq.empty()){
            int hc=pq.top().first;
            int hy=pq.top().second.first;
            int hx=pq.top().second.second;
            
            pq.pop();

            if(dist[hy][hx]<hc) continue;
            
            // cout<<i<<"hc : "<<hc<<" , hy : "<<hy<<" , hx : "<<hx<<endl;

            for(int j=0; j<4; j++){
                int ny=hy+dy[j];
                int nx=hx+dx[j];
                if(!isinside(ny,nx))continue;
                int nc=hc+arr[ny][nx]; //현재위치까지의거리랑 다음까지거리
                if(nc<dist[ny][nx]){
                    dist[ny][nx]=nc;
                    pq.push({nc,{ny,nx}});
                }
            }
        }
        cout<<"Problem "<<i<<": "<<dist[n-1][n-1]<<endl;
        i++;
    }
} //다익스트라사용
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}