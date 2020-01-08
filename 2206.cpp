#include <bits/stdc++.h>
using namespace std;

int n,m;
const int MAX=1000;
int arr[MAX][MAX];
int dist[2][MAX][MAX];

bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int res=-1;

void bfs(int y, int x){

    queue<pair<pair<int,int>,int>> q;
    q.push({{y,x},0});
    dist[0][0][0]=1;
    while(!q.empty()){
        int hy=q.front().first.first;
        int hx=q.front().first.second;
        int cnt=q.front().second;
       // cout<<"hy : "<<hy<<" , "<<"hx : "<<hx<<" ,"<<"dist : "<<dist[cnt][hy][hx]<<"\n";
        q.pop();

        if(hy==n-1 &&hx==m-1){
            res=dist[cnt][hy][hx];
            return ;
        }
        for(int i=0 ; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(isinside(ny,nx)&&!dist[cnt][ny][nx]){
                if(!arr[ny][nx]){
                    dist[cnt][ny][nx]=dist[cnt][hy][hx]+1;
                    q.push({{ny,nx},cnt});
                }
                if(arr[ny][nx]==1 && cnt==0){
                    dist[1][ny][nx]=dist[cnt][hy][hx]+1;
                    q.push({{ny,nx},1});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d %d", &n, &m);
 	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

    bfs(0,0);
    cout<<res<<"\n";

    
    return 0;
}