#include <bits/stdc++.h>
using namespace std;
int t;
int w,h;
const int MAX=1000;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
bool isinside(int y, int x){
    if(y>=0 && y<h && x>=0 && x<w){
        return true;
    }
    return false;
}
char Fire[MAX][MAX];
typedef struct pos{
    int y,x,sec;
    bool type;
}pos;
pos sp;
queue<pos>q;
void input(){
    cin>>w>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>Fire[i][j];
            if(Fire[i][j]=='@'){
                sp.y=i;
                sp.x=j;
            }
            else if(Fire[i][j]=='*'){
                q.push({i,j,0,false});
            }
        }
    }
}
bool visited[MAX][MAX];
void emptyforq(){
    while(!q.empty())q.pop();
}

int bfs(){
    visited[sp.y][sp.x]=true;
    q.push({sp.y,sp.x,0,true}); //불먼저 태워야함
    while(!q.empty()){
        int hy=q.front().y;
        int hx=q.front().x;
        int pop_sec=q.front().sec;
        int pop_type=q.front().type;
        q.pop();

        if(pop_type && (hy==0 || hy==h-1||hx==0||hx==w-1))return pop_sec+1;

        for(int i=0 ; i<4; i++){
            int ny =hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(Fire[ny][nx]=='#'||Fire[ny][nx]=='*')continue;
            if(visited[ny][nx])continue;

            if(pop_type)visited[ny][nx]=true;
            else Fire[ny][nx]='*';

            q.push({ny,nx,pop_sec+1,pop_type});

        }
    }

    return 0;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++){
        emptyforq();
        input();
        memset(visited,false,sizeof(visited));
        
        int ret=bfs();
        if(ret)cout<<ret<<"\n";
        else cout<<"IMPOSSIBLE"<<"\n";
    }

    return 0;
}
//참고해서풀었습니다.https://donggod.tistory.com/18