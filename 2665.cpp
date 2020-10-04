#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<vector<int>> MAP;
vector<vector<vector<int>>> dist;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
int black;
bool IsInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n)
        return true;
    return false;
}

void Init(){
    cin>>n;
    MAP.resize(n,vector<int>(n));
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<n; j++){
            MAP[i][j]=temp[j]-'0';
            if(MAP[i][j]==0)
                black++;
        }
    }
    dist.resize(black+1,vector<vector<int>>(n,vector<int>(n,1e9)));
}
void Solve(){
    queue<tuple<int,int,int>> q;
    dist[0][0][0]=0;
    q.push(make_tuple(0,0,0));
    while(!q.empty()){
        int hCount,hy,hx;
        tie(hCount,hy,hx)=q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;

            if(!IsInside(ny,nx))continue;
            if(MAP[ny][nx]==1){
                if(dist[hCount][ny][nx]>dist[hCount][hy][hx]+1){
                    q.push({hCount,ny,nx});
                    dist[hCount][ny][nx]=dist[hCount][hy][hx]+1;
                }   
            }
            if(MAP[ny][nx]==0){
                if(hCount+1>=black)continue;
                if(dist[hCount+1][ny][nx]>dist[hCount][hy][hx]+1){
                    q.push({hCount+1,ny,nx});
                    dist[hCount+1][ny][nx]=dist[hCount][hy][hx]+1;
                }
            }
        }
    }
    
    for(int i=0; i<black; i++){
        if(dist[i][n-1][n-1]!=1e9){
            cout<<i<<endl;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    return 0;
}