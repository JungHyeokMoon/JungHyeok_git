#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,l,r;
vector<vector<int>> arr;
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n){
        return true;
    }
    return false;
}
vector<vector<bool>> visited; //
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
int ret=0;
bool check=true;  //인구변화가 있었냐 없었냐의 변수
void Input(){
    cin>>n>>l>>r;
    arr.resize(n);
    visited.resize(n);
    for(int i=0; i<n; i++){
        arr[i].resize(n);
        visited[i].resize(n,false);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
}
bool isOk(int y, int x){
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isinside(ny,nx))continue;
        if(visited[ny][nx])continue;
        int diff=abs(arr[y][x]-arr[ny][nx]);
        if(l<=diff && diff<=r){
            return true;
        }
    }
    return false;
}
void Print(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void bfs(int y, int x){
    queue<pair<int,int>> unite;
    queue<pair<int,int>> q;
    q.push({y,x});
    unite.push({y,x});
    visited[y][x]=true;
    int sum=0;
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        q.pop();

        sum+=arr[hy][hx];
        // cout<<"sum : "<<sum<<endl;
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(visited[ny][nx])continue;
            int diff=abs(arr[hy][hx]-arr[ny][nx]);
            if(l<=diff && diff<=r){
                q.push({ny,nx});
                unite.push({ny,nx});
                visited[ny][nx]=true;
            }
        }
    }
    int area=unite.size();
    int pushnum=sum/area;
    while(!unite.empty()){
        int hy=unite.front().first;
        int hx=unite.front().second;
        unite.pop();
        arr[hy][hx]=pushnum;
    }
}
void Solve(){
    while(check){
        for(int i=0; i<n; i++){
            fill(visited[i].begin(),visited[i].begin()+n,false);
        }//visitd초기화
        check=false; //check 초기화
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && isOk(i,j)){ //아직방문하지않았고 주위에 인구이동할공간이있으면
                    check=true;
                    bfs(i,j);
                    
                }
            }
        }
        // Print();
        if(check)ret++;
    }
    cout<<ret<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}