#include <bits/stdc++.h>
using namespace std;

int n,k;
int virus[50][50];
int ret=987654321;
//bool forvirus[50][50];
bool forbfs[50][50];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n){
        return true;
    }
    return false;
}
int c=0;
vector<pair<int,int>>v;
vector<pair<int,int>>virus_v;
bool forvirus[10];
void bfs(){
    queue<pair<pair<int,int>,int>> q;
    /*bool flag=false;
    int x=k;
    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            if(x<=0){
                flag=true;
                break;
            }
            if(forvirus[i][j]&&virus[i][j]==2){
                q.push(make_pair(make_pair(i,j),0));
                forbfs[i][j]=true;
                x--;
            }
        }
        if(flag)break;
    } // 바이러스삽입
    */
    for(int i=0; i<virus_v.size(); i++){
        forbfs[virus_v[i].first][virus_v[i].second]=true;
        q.push(make_pair(make_pair(virus_v[i].first,virus_v[i].second),0));
    }
    while(!q.empty()){
        int hy=q.front().first.first;
        int hx=q.front().first.second;
        int hd=q.front().second;

        c=max(c,hd);
        q.pop();
        for(int i=0; i<4; i++){
            int ny=hy+dy[i];
            int nx=hx+dx[i];
            if(!isinside(ny,nx))continue;
            if(forbfs[ny][nx])continue;
            if(virus[ny][nx]==0 || virus[ny][nx]==2){
                forbfs[ny][nx]=true;
                q.push(make_pair(make_pair(ny,nx),hd+1));
            }
        }
    }

    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            if(!forbfs[i][j]){
                if(virus[i][j]==0 || virus[i][j]==2){
                    c=987654321;
                    return ;
                }
            }
        }
    }
}

void solve(int idx,int cnt){
    if(cnt==k){
        c=0;
        memset(forbfs,false,sizeof(forbfs));
        bfs();
        
        ret=min(ret,c);
        return ;
    }

    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!forvirus[i][j] && virus[i][j]==2){
                forvirus[i][j]=true;
                solve(cnt+1);
                forvirus[i][j]=false;
            }
        }
    } //바이러스놓는경우*/

    for(int i=idx; i<v.size(); i++){
        if(forvirus[i])continue;
        forvirus[i]=true;
        virus_v.push_back(v[i]);
        solve(i,cnt+1);
        virus_v.pop_back();
        forvirus[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>virus[i][j];
            if(virus[i][j]==2){
                v.push_back(make_pair(i,j)); //조합을위해서 이렇게 넣어줘야함
            }
        }
    }

    solve(0,0);
    if(ret==987654321){
        cout<<-1<<"\n";
    }
    else{
        cout<<ret<<"\n";
    }
    return 0;
}