#include <bits/stdc++.h>
using namespace std;

int r,c;
char swan[1500][1500];

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
bool isvisited[1500][1500];
int ret=0;
bool flag=false;
bool isinside(int y, int x){
    if(y>=0 && y<r && x>=0 && x<c){
        return true;
    }
    return false;
}

queue<pair<int,int>> water_q,water_nq,swan_q,swan_nq;
typedef struct pos{
    int y,x;
}pos;
pos swancoordi[2];
bool swan_bfs(){

    while(!swan_q.empty()){
        int hy=swan_q.front().first;
        int hx=swan_q.front().second;
        swan_q.pop();
        if(hy==swancoordi[1].y && hx==swancoordi[1].x){
            return true;
        }
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(isvisited[ny][nx])continue;
            if(swan[ny][nx]=='.' || swan[ny][nx]=='L'){
                isvisited[ny][nx]=true;
                swan_q.push(make_pair(ny,nx));
            }
            else{
                isvisited[ny][nx]=true;
                swan_nq.push(make_pair(ny,nx));
            }
            
        }
    }

    return false;
}
void water_bfs(){
    while(!water_q.empty()){
        int hy=water_q.front().first;
        int hx=water_q.front().second;
        water_q.pop();
        for(int i=0; i<4 ; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(swan[ny][nx]=='X'){
                swan[ny][nx]='.';
                water_nq.push(make_pair(ny,nx));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r>>c;
    int k=0;
    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            swan[i][j]=temp[j];
            if(swan[i][j]!='X')water_q.push(make_pair(i,j));
            if(swan[i][j]=='L'){
                swancoordi[k++]={i,j};
            }
        }
    }

    swan_q.push(make_pair(swancoordi[0].y,swancoordi[0].x));
    isvisited[swancoordi[0].y][swancoordi[0].x]=true;
    while(1){
        
        
        flag=swan_bfs();
        if(flag){
            cout<<ret<<"\n";
            break;
        }
        water_bfs();
        water_q=water_nq;
        swan_q=swan_nq;

        while(!water_nq.empty())water_nq.pop();
        while(!swan_nq.empty())swan_nq.pop();
        ret++;
    }

    
    
    return 0;
}