#include <bits/stdc++.h>
using namespace std;
char Puyo[12][6];
int ret=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isinside(int y,int x){
    if(y>=0 && y<12 &&x>=0 &&x<6){
        return true;
    }
    return false;
}
bool bfs(int y,int x){
    bool flag=false;
    bool isvisited[12][6]={false};
    isvisited[y][x]=true;
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    char temp=Puyo[y][x];
    q.push({y,x});
    v.push_back({y,x});
    int cnt=0;
    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;
        cnt++;
        q.pop();

        for(int i=0; i<4 ; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(isvisited[ny][nx])continue;
            if(Puyo[ny][nx]==temp){
                q.push({ny,nx});
                isvisited[ny][nx]=true;
                v.push_back({ny,nx});

            }
        }
    }
    if(cnt>=4){
        flag=true;
        for(int i=0; i<v.size(); i++){
            Puyo[v[i].first][v[i].second]='.';
        }
    }
    return flag;
}

void Input(){
    for(int i=0; i<12 ; i++){
        for(int j=0; j<6; j++){
            cin>>Puyo[i][j];
        }
    }
}
void Output(){
    cout<<"\\\\\\\\"<<"\n";
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cout<<Puyo[i][j];
        }
        cout<<"\n";
    }
}
bool Crash(){
    bool flag=false;
    for(int i=11; i>=0 ;i--){
        for(int j=5; j>=0; j--){
            if(Puyo[i][j]=='.')continue;
            if(bfs(i,j))flag=true;
        }
    }
    return flag;
}
void fall(){
    for(int j=0; j<6; j++){
        for(int i=11; i>=0; i--){
            if(Puyo[i][j]=='.')continue;
            for(int k=11; k>=i; k--){
                if(Puyo[k][j]=='.'){
                    Puyo[k][j]=Puyo[i][j];
                    Puyo[i][j]='.';
                }
            }
        }
    }
}
void Solve(){
    int ans=0;
    while(Crash()){
        //Output();
        fall();
        ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}