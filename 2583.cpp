#include <bits/stdc++.h>
using namespace std;

int m,n,k;
const int MAX=100;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int cnt=0;
vector<int > ret;
bool isinside(int y, int x){
    if(y>=0 && y<m && x>=0 && x<n){
        return true;
    }
    return false;
}

void check_area(int x1,int y1, int x2, int y2){
    for(int i=y1; i<y2; i++){
        for(int j=x1; j<x2; j++){
            arr[i][j]=-1;
        }
    }
}

void bfs(int y, int x){
    int area=0;
    queue<pair<int,int>> q;

    q.push({y,x});
    visited[y][x]=true;

    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        area++;
        q.pop();
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(isinside(ny,nx)&& arr[ny][nx]==0 && visited[ny][nx]==false){
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }

    ret.push_back(area);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>n>>k;
    for(int i=0; i<k; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        check_area(x1,y1,x2,y2);
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0&&visited[i][j]==0){
                bfs(i,j);
            }
        }
    }

    
    //답출력
    
    sort(ret.begin(),ret.end());
    int len=ret.size();
    cout<<len<<"\n";
    for(int i=0; i<len; i++){
        cout<<ret[i]<<" ";
    }
    cout<<"\n";
    

    return 0;

}