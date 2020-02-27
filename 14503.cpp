#include <bits/stdc++.h>
using namespace std;
int MAP[50][50];
int n,m;
int r,c,d; //d :0 ->북 , 1 ->동 ,2->남 ,3->서쪽 r,c 로봇의좌표
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}
int turndirection(int d){
    if(d==0)return 3;
    if(d==1)return 0;
    if(d==2)return 1;
    if(d==3)return 2;
}
int backturndirection(int d){
    if(d==0)return 2;
    if(d==1)return 3;
    if(d==2)return 0;
    if(d==3)return 1;
}
int ret=0;
bool isvisited[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void bfs(){
    isvisited[r][c]=true;
    queue<pair<pair<int,int>,int>>q;
    q.push({{r,c},d});    

    while(!q.empty()){
        int hy=q.front().first.first;
        int hx=q.front().first.second;
        int hd=q.front().second;
        
        
        q.pop();
        
        bool flag=false;
        int nd=hd;
        for(int i=0; i<4; i++){
            nd=turndirection(nd);
            int ny=hy+dy[nd];
            int nx=hx+dx[nd];
            if(!isinside(ny,nx))continue;
            
            if(MAP[ny][nx]==0&&!isvisited[ny][nx]){
                flag=true;
                isvisited[ny][nx]=true;
                q.push({{ny,nx},nd});
                ret++;
                break;
            }
        }

        if(!flag){
            nd=backturndirection(hd);
            int ny=hy+dy[nd];
            int nx=hx+dx[nd];
            if(isinside(ny,nx) && MAP[ny][nx]==0){
                q.push({{ny,nx},hd});
            }
        }//후진

    }
    

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    cin>>r>>c>>d;

    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cin>>MAP[i][j];
        }
    }
    bfs();
    cout<<ret+1<<"\n";
    return 0;
}