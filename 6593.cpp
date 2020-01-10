#include <bits/stdc++.h>
using namespace std;
int L,R,C;
const int MAX=30;
char building[MAX][MAX][MAX];
typedef struct pos{
    int x,y,z;
}pos ;
pos start,endp;
bool visited[MAX][MAX][MAX];
void init(){
    for(int k=0; k<L; k++){
        for(int i=0; i<R; i++){
            fill(building[k][i],building[k][i]+C,false);
        }
    }
    for(int k=0; k<L; k++){
        for(int i=0; i<R; i++){
            fill(visited[k][i],visited[k][i]+C,false);
        }
    }
}
int dz[]={1,-1,0,0,0,0};
int dy[]={0,0,0,1,0,-1};
int dx[]={0,0,-1,0,1,0};

bool isinside(int z,int y, int x){
    if(z>=0 && z<L && y>=0 && y<R && x>=0 && x<C)
        return true;
    return false;
}

void bfs(int z, int y, int x){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    
    visited[z][y][x]=true;
    q.push({{y,x},{z,0}});

    while(!q.empty()){
        int hy=q.front().first.first;
        int hx=q.front().first.second;
        int hz=q.front().second.first;
        int hd=q.front().second.second;
        q.pop();

        if(hz==endp.z && hy==endp.y && hx==endp.x){
            cout<<"Escaped in "<<hd<<" "<<"minute(s)."<<"\n";
            return;
        }
        for(int i=0; i<6; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            int nz=hz+dz[i];
            if(isinside(nz,ny,nx)&&!visited[nz][ny][nx]&&(building[nz][ny][nx]=='.'||building[nz][ny][nx]=='E')){
                visited[nz][ny][nx]=true;
                q.push({{ny,nx},{nz,hd+1}});
            }
        }
    }
    cout<<"Trapped!"<<"\n";
    return ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin>>L>>R>>C;
        if(L==0 && R==0 && C==0)return 0;
        init();
        for(int k=0; k<L; k++){
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    cin>>building[k][i][j];
                    if(building[k][i][j]=='S'){
                        start.z=k;
                        start.y=i;
                        start.x=j;
                    }
                    else if(building[k][i][j]=='E'){
                        endp.z=k;
                        endp.y=i;
                        endp.x=j;
                    }
                }
            }
        }
        bfs(start.z,start.y,start.x);
    }
    

    return 0;

}