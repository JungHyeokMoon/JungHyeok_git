#include <bits/stdc++.h>
using namespace std;
int n,m;   
const int MAX=300;
int iceberg[MAX][MAX];
int C_iceberg[MAX][MAX];
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}
bool visited[MAX][MAX];
int year;
void copyMap(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m ; j++){
            iceberg[i][j]=C_iceberg[i][j];
        }
    }
}

int Melt(int y, int x){
    int cnt=0;
    for(int i=0; i<4 ; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(isinside(ny,nx)&&!iceberg[ny][nx])cnt++;
    }
    return cnt;
}

void bfs(int y,int x){
    queue<pair<int,int>>q;
    visited[y][x]=true;
    q.push({y,x});

    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        q.pop();
        //cout<<"year : "<<year<<" , "<<"hy : "<<hy<<" , "<<"hx : "<<hx<<"\n";
        for(int i=0 ; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];

            if(isinside(ny,nx) && !visited[ny][nx] && iceberg[ny][nx]){
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>iceberg[i][j];
        }
    }
    
    while(1){
        int LandCount=0;
        memset(visited,false,sizeof(visited));
        memset(C_iceberg,0,sizeof(C_iceberg));

        for(int i=0 ; i< n ; i++){
            for(int j=0; j< m; j++){
                if(!visited[i][j]&&iceberg[i][j]){
                   //cout<<"i : "<<i<<", j : "<<j<<"\n";
                    LandCount++;
                    bfs(i,j);
                }
            }
        }
       // cout<<"year : "<<year<<" , "<<"Landcount : "<<LandCount<<"\n";

        if(LandCount>=2){
            cout<<year<<"\n";
            return 0;
        }
        else if(!LandCount){
            cout<<"0"<<"\n";
            return 0;
        }

        for(int i=0 ; i< n ;i++){
            for(int j=0; j<m; j++){
                if(iceberg[i][j]){
                    C_iceberg[i][j]=iceberg[i][j]-Melt(i,j);
                    if(C_iceberg[i][j]<0)C_iceberg[i][j]=0;
                }
            }
        }

        copyMap();
        year++;
    }

    return 0;
}