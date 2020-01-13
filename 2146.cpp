#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX=100;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n){
        return true;
    }
    return false;
}
int bridge[MAX][MAX];
bool visited[MAX][MAX];

void input(){
    cin>>n;
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cin>>bridge[i][j];
            if(bridge[i][j]==1)bridge[i][j]=-1;
        }
    }
}
void makeland(int y, int x,int l){
    visited[y][x]=true;
    queue<pair<int,int>> q;
    q.push({y,x});
    bridge[y][x]=l;
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(isinside(ny,nx)&&!visited[ny][nx]&&bridge[ny][nx]==-1){
                visited[ny][nx]=true;
                bridge[ny][nx]=l;
                q.push({ny,nx});
            }
        }
    }
}
int ret=987654321;

int bfs(int L){
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(bridge[i][j]==L){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }

    int result=0;
    while(!q.empty()){
        int qsize=q.size();
        for(int i=0; i<qsize; i++){
            int hy=q.front().first;
            int hx=q.front().second;
            q.pop();

            for(int j=0; j<4; j++){
                int ny=hy+dy[j];
                int nx=hx+dx[j];
                if(!isinside(ny,nx))continue;

                if(bridge[ny][nx]!=L&&bridge[ny][nx]!=0)return result;
                if(visited[ny][nx])continue;
                if(bridge[ny][nx]==0){
                    q.push({ny,nx});
                    visited[ny][nx]=true;
                }
            }
        }
        result++;
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    input();
    int Land=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]&&bridge[i][j]==-1){
                makeland(i,j,Land);
                Land++;
            }
        }
    }


    for(int i=1; i<Land; i++){
        memset(visited,false,sizeof(visited));
        ret=min(ret,bfs(i));  
    }

    cout<<ret<<"\n";
    return 0;
}