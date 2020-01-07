#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX=100;
char MAP[MAX][MAX];
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
bool visited[MAX][MAX];
int ret1=0;
int ret2=0;
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n){
        return true;
    }
    return false;
}

void input(){
    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cin>>MAP[i][j];
        }
    }
}


void output(){
    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cout<<MAP[i][j];
        }
        cout<<"\n";
    }
}

void init(){
    for(int i=0; i<n ; i++){
        fill(visited[i],visited[i]+n,false);
    }
}

void bfs(int y, int x,bool flag){ // flag가 false 인경우 는 적록색약이 아닌경우
    char temp=MAP[y][x];
    queue<pair<int,int>> q;

    q.push({y,x});
    visited[y][x]=true;

    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(visited[ny][nx])continue;
            if(flag){
                if(MAP[ny][nx]==temp){
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }//적록색약이아닌경우
            else{
                if(temp=='B'){
                    if(MAP[ny][nx]=='B'){
                        visited[ny][nx]=true;
                        q.push({ny,nx});
                    }
                }
                else{
                    if(MAP[ny][nx]=='G'||MAP[ny][nx]=='R'){
                        visited[ny][nx]=true;
                        q.push({ny,nx});
                    }
                }
            }//적록색약인경우
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    input();
    init();

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            if(!visited[i][j]){
                bfs(i,j,true);
                ret1++;
            }
        }
    } //적록색약이아닌경우

    init();

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            if(!visited[i][j]){
                bfs(i,j,false);
                ret2++;
            }
        }
    } //적록색약인경우

    cout<<ret1<<"\n"<<ret2<<"\n";

    return 0;
}