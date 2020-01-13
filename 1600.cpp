#include <bits/stdc++.h>
using namespace std;

const int MAX=200;
int K;
int W,H;
bool isinside(int y, int x){
    if(y>=0 && y<H && x>=0 && x<W){
        return true;
    }
    return false;
}
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
bool isvisted[MAX][MAX][31];
int diagonaldy[8]={-1,-2,-2,-1,1,2,2,1};
int diagonaldx[8]={-2,-1,1,2,2,1,-1,-2};
int monkey[MAX][MAX];

int ret=-1;

typedef struct Solve{
    int y,x,k,t;
}Solve;
int bfs(int y, int x){
    queue<Solve> q;
    isvisted[y][x][0]=true;
    q.push({y,x,0,0});

    while(!q.empty()){
        int hy=q.front().y;
        int hx=q.front().x;
        int hk=q.front().k;
        int ht=q.front().t;
        //cout<<"hy : "<<hy<<" , "<<"hx : "<<hx<<" , "<<"hk : "<<hk<<" , "<<"ht : "<<ht<<"\n";
        q.pop();
        if(hy==H-1 &&hx==W-1)return ht;

        if(hk<K){
            for(int i=0; i<8; i++){
                int ny=hy+diagonaldy[i];
                int nx=hx+diagonaldx[i];
                if(!isinside(ny,nx))continue;
                
                if(monkey[ny][nx]==0&&!isvisted[ny][nx][hk+1]){
                    isvisted[ny][nx][hk+1]=true;
                    
                    q.push({ny,nx,hk+1,ht+1});
                }
            }
        }
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            
            if(monkey[ny][nx]==0&&!isvisted[ny][nx][hk]){
                isvisted[ny][nx][hk]=true;
                
                q.push({ny,nx,hk,ht+1});
            }
        }
    }

    return -1;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>K;
    cin>>W>>H;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>monkey[i][j];
        }
    }

    cout<<bfs(0,0)<<"\n";
    return 0;
}
//조건이 주어져있는경우는 3차원배열을생각해봐야함