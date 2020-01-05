#include <bits/stdc++.h>
using namespace std;

const int MAX=500;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int n,m;

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

int cnt=0;
int ret=0;

bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}

void bfs(int hy, int hx){
    queue<pair<int,int>> y_x;

    y_x.push({hy,hx});
    int hd=0;
    visited[hy][hx]=true; //방문했다.
    while(!y_x.empty()){
        int hy=y_x.front().first;
        int hx=y_x.front().second;
        hd++;
        y_x.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(isinside(ny,nx)&&arr[ny][nx]==1&&visited[ny][nx]==false){ //내부에있고 , arr이 1이고 방문하지않았으면
                y_x.push({ny,nx});
                visited[ny][nx]=true;
                
            }
        }
    }
    ret=max(ret,hd);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1&&!visited[i][j]){//1이고 방문하지않은곳을 bfs로돈다
                bfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<"\n";
    cout<<ret<<"\n";

    return 0;
}