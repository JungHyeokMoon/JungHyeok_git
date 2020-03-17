#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,K;
vector<vector<char>> MAP;
vector<vector<bool>> isvisited;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
int ret=0;
void Input(){
    cin>>R>>C>>K;
    MAP.resize(R);
    isvisited.resize(R);
    for(int i=0; i<R ; i++){
        MAP[i].resize(C);
        isvisited[i].resize(C,false);
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C ;j++){
            cin>>MAP[i][j];
            // if(MAP[i][j]=='T')cout<<i<<" ,"<<j<<endl;
        }
    }
}

bool isinside(int y, int x){
    if(y>=0 && y<R && x>=0 && x<C){
        return true;
    }
    return false;
}

void dfs(pair<int,int> hc,int cnt){
    // if(cnt>K){
    //     return ;
    // }
    int hy=hc.first;
    int hx=hc.second;
    // cout<<"hy : "<<hy<<" , hx : "<<hx<<" , cnt : "<<cnt<<endl;
    if(cnt==K){
        if(hy==0 && hx==C-1){
            ret++;
            // cout<<ret<<endl;
            return ;
        }
    }

    for(int i=0; i<4 ; i++){
        int ny=hy+dy[i];
        int nx=hx+dx[i];
        if(!isinside(ny,nx))continue;
        if(MAP[ny][nx]=='T')continue;
        if(isvisited[ny][nx])continue;
        if(cnt+1>K)continue;
        isvisited[ny][nx]=true;
        dfs({ny,nx},cnt+1);
        isvisited[ny][nx]=false;
    }


}
void Solve(){
    isvisited[R-1][0]=true;
    dfs({R-1,0},1);
    cout<<ret<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}