#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX=100;
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n){
        return true;
    }
    return false;
}
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int arr[MAX][MAX];

int max_range=-987654321;
bool visited[MAX][MAX];
int ret=-987654321;

void init(){
    for(int i=0; i<n; i++){
        fill(visited[i],visited[i]+n,false);
    }
}

void bfs(int y, int x,int range){
   // cout<<"bfs here"<<"\n";
    queue<pair<int,int >>q;
    q.push({y,x});
    visited[y][x]=true;

    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(isinside(ny,nx)&&!visited[ny][nx]&&arr[ny][nx]>range){
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            max_range=max(max_range,arr[i][j]);
        }
    }
    //cout<<"max_range : "<<max_range<<"\n";
    for(int k=0; k<=max_range; k++){
        init();
        int temp=0;
        //cout<<"k : "<<k<<"\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //cout<<"i : "<<i<<" , "<<"j : "<<j<<"\n";
                if(!visited[i][j] && arr[i][j]>k){// N 이하인 애들이 잠긴다. 그래서 초과인애들 bfs돌려서 몇개인지 찾아야함 
                    temp++;
                    bfs(i,j,k);
                    //cout<<"k : "<<k<<" , "<<"temp : "<<temp<<"\n";
                }
            }
        }
        ret=max(ret,temp);
    }


    cout<<ret<<"\n";
    return 0;

}