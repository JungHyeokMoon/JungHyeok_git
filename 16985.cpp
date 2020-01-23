#include <bits/stdc++.h>
using namespace std;

int Maze[5][5][5];
int C_Maze[5][5][5];
int dz[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,0,-1,0};
int dx[6]={0,0,0,1,0,-1};
bool isvisited[5][5][5];
int Maze_order[5];
int Turn_order[5];
bool Select[5];
int ret=987654321;
bool isinside(int z, int y, int x){
    if(z>=0 && z<5 && y>=0 && y<5 && x>=0 &&x<5){
        return true;
    }
    return false;
}


int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>>q;
    q.push({{0,0},{0,0}});
    isvisited[0][0][0]=true;

    while(!q.empty()){
        int hz=q.front().first.first;
        int hy=q.front().first.second;
        int hx=q.front().second.first;
        int cnt=q.front().second.second;

        q.pop();
        if(hz==4 && hy==4 && hx==4){
            return cnt;
        }
        for(int i=0; i<6; i++){
            int nz=hz+dz[i];
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(nz,ny,nx))continue;
            if(isvisited[nz][ny][nx])continue;
            if(C_Maze[nz][ny][nx]==1){
                q.push({{nz,ny},{nx,cnt+1}});
                isvisited[nz][ny][nx]=true;
            }
        }
    }
    return -1;
}
void Make_Maze(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                C_Maze[i][j][k]=-1;
            }
        }
    } //초기화작업

    for(int i=0; i<5; i++){
        int idx=Maze_order[i];
        int Turn=Turn_order[i];
        if(Turn==0){
            for(int x=0; x<5 ;x++){
                for(int y=0; y<5 ; y++){
                    C_Maze[i][x][y]=Maze[idx][x][y];
                }
            }
        }//그대로
        else if(Turn==1){
            for(int x=0; x<5 ; x++){
                for(int y=0; y<5; y++){
                    C_Maze[i][x][y]=Maze[idx][y][4-x];
                }
            }
        }//90도회전
        else if(Turn==2){
            for(int x=0; x<5; x++){
                for(int y=0; y<5; y++){
                    C_Maze[i][x][y]=Maze[idx][4-x][4-y];
                }
            }
        }//180도회전
        else{
            for(int x=0; x<5; x++){
                for(int y=0; y<5; y++){
                    C_Maze[i][x][y]=Maze[idx][4-y][x];
                }
            }
        }
    }
}
void Make_Maze_Turn_Order(int cnt){
    if(cnt==5){
        Make_Maze();
        if(C_Maze[0][0][0]==1 && C_Maze[4][4][4]==1){
            memset(isvisited,false,sizeof(isvisited));
            int result=bfs();
            if(result!=-1){
                ret=min(ret,result);
            }
        }
        return ;
    }

    for(int Turn=0; Turn<4; Turn++){
        Turn_order[cnt]=Turn;
        Make_Maze_Turn_Order(cnt+1);
    }
}
void Make_Maze_Order(int cnt){
    if(cnt==5){
        Make_Maze_Turn_Order(0);
        return ;
    }

    for(int i=0; i<5 ; i++){
        if(Select[i])continue;
        Select[i]=true;
        Maze_order[i]=cnt;
        Make_Maze_Order(cnt+1);
        Select[i]=false;
        Maze_order[i]=-1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin>>Maze[i][j][k];
            }
        }
    }//0은 참가자가 들어갈수없는칸 , 1 은 참가자가 들어갈수 있는칸
    for(int i=0; i<5; i++){
        Maze_order[i]=-1;
        Turn_order[i]=-1;
    }
    Make_Maze_Order(0);
    if(ret==987654321){
        cout<<-1<<"\n";
    }
    else{
        cout<<ret<<"\n";
    }
}