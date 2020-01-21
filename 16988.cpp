#include <bits/stdc++.h>
using namespace std;

int n,m;
int baduk[20][20];
bool isvisited[20][20];
int ret=0;
bool visited[20][20];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
bool isinside(int y,int x){
    if(y>=0 && y<n && x>=0 &&x<m){
        return true;
    }
    return false;
}
bool zero=false;

int bfs(int y, int x){
    visited[y][x]=true;
    queue<pair<int,int>>q;
    q.push(make_pair(y,x));
    
    int cnt=0;
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        
        cnt++;
        //cout<<"hy : "<<hy<<" hx : "<<hx<<" , "<<"cnt : "<<cnt<<"\n";
        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx)) continue;
            if(baduk[ny][nx]==1)continue;
            if(visited[ny][nx])continue;
            if(baduk[ny][nx]==2){
                q.push({ny,nx});
                visited[ny][nx]=true;
            }
            else if(baduk[ny][nx]==0){
                zero=true;
            }
            
        }
    }

    return cnt;
}


void solve(int cnt){
    if(cnt==2){
        int s=0;
        memset(visited,false,sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j]&&baduk[i][j]==2){
                    zero=false;
                    int size=0;
                    size=bfs(i,j);
                    if(zero)size=0;
                    s+=size;
                }
            }
        }
        ret=max(ret,s);
        return ;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!isvisited[i][j]&&baduk[i][j]==0){
                isvisited[i][j]=true;
                baduk[i][j]=1;
                solve(cnt+1);
                isvisited[i][j]=false;
                baduk[i][j]=0;
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
            cin>>baduk[i][j];
        }
    } // 0 빈칸 , 1나의돌, 2상대돌


    solve(0);

    cout<<ret<<"\n";
    return 0;
}