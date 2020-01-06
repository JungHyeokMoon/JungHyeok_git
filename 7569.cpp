#include <bits/stdc++.h>
using namespace std;

int m,n,h; // m:가로, n:세로 , h:높이
const int MAX=100;
int tomato[MAX][MAX][MAX];
//bool visited[MAX][MAX][MAX];

int dy[6]={0,0,0,0,-1,1};
int dx[6]={0,0,-1,1,0,0};
int dz[6]={1,-1,0,0,0,0};
int ret=0;
bool isinside(int y,int x,int z){
    if(y>=0 && y<n &&x>=0 &&x<m &&z>=0 &&z<h){
        return true;
    }
    return false;
}
queue<pair<pair<int,int>,int>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>n>>h;
    
    //int cnt=0;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>tomato[i][j][k];
                if(tomato[i][j][k]==1){
                    q.push({{i,j},k});
                }
            }
        }
    }

    if(q.empty()){
        cout<<"0"<<"\n";
        return 0;
    } //

    while(!q.empty()){
        int hy=q.front().first.first;
        int hx=q.front().first.second;
        int hz=q.front().second;

        q.pop();

        for(int i=0; i<6 ; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            int nz=hz+dz[i];
            if(isinside(ny,nx,nz)&&tomato[ny][nx][nz]==0 ){
                tomato[ny][nx][nz]=tomato[hy][hx][hz]+1;
                q.push({{ny,nx},nz});
            }
        }
    }


    int ret=-987654321;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(tomato[i][j][k]==0){
                    cout<<"-1"<<"\n";
                    return 0;
                }
                ret=max(ret,tomato[i][j][k]);
            }
        }
    }
    
    cout<<ret-1<<"\n";
    
    return 0;
}