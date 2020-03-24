#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};

int n,m;
vector<vector<int>> MAP;
vector<vector<int>>dist; //dist[y][x] yx까지 최소로 뿌신문의갯수
typedef pair<int,pair<int,int>> pii;
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}
void Input(){
    cin>>m>>n; //가로크기 m 세로크기 n
    MAP.resize(n);
    dist.resize(n);
    for(int i=0; i<n; i++){
        MAP[i].resize(m);
        dist[i].resize(m);
        fill(dist[i].begin(),dist[i].begin()+m,987654321);
    }
    
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<m; j++){
            MAP[i][j]=temp[j]-'0';
        }
    }
}
void dijkstra(){
    dist[0][0]=0;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        int hd=pq.top().first;
        int hy=pq.top().second.first;
        int hx=pq.top().second.second;
        pq.pop();

        if(dist[hy][hx]<hd){ //hd+1<dist[ny][nx] 갱신을할건데 어짜피 hd가커버리면안되니깐
            continue;   //현재꺼냈을때보다 거리가 이미작다면 continue
        }
        if(hy==n-1 && hx==m-1){
            dist[n-1][m-1]=hd;
            return ;
        }

        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            
            if(MAP[ny][nx]==1){
                if(hd+1<dist[ny][nx]){
                    dist[ny][nx]=hd+1;
                    pq.push({dist[ny][nx],{ny,nx}});
                }
            }
            else{
                if(hd<dist[ny][nx]){
                    dist[ny][nx]=hd;
                    pq.push({dist[ny][nx],{ny,nx}});
                }
            }
            
        }
    }
}
void Solve(){
    dijkstra();
    cout<<dist[n-1][m-1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}