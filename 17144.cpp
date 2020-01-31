#include <bits/stdc++.h>
using namespace std;

int R,C,T;
int fine_dust[50][50];
int C_fine_dust[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isinside(int y, int x){
    if(y>=0 && y<R && x>=0 &&x<C){
        return true;
    }
    return false;
}
typedef struct pos{
    int y,x;
}pos;
pos Aircleaner[2];
int Count(){
    int sum=0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(fine_dust[i][j]==-1)continue;
            sum+=fine_dust[i][j];
        }
    }
    return sum;
}
void Input(){
    cin>>R>>C>>T;
    int Idx=0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>fine_dust[i][j];
            if(fine_dust[i][j]==-1){
                Aircleaner[Idx].y=i;
                Aircleaner[Idx].x=j;
                Idx++;
            }
        }
    }
}
void Air(){
    for(int Idx=0; Idx<2; Idx++){
        if(Idx==0){
            for(int i=Aircleaner[Idx].y-1; i>0 ; i--){
                fine_dust[i][0]=fine_dust[i-1][0];
            }
            for(int i=0; i<C-1; i++){
                fine_dust[0][i]=fine_dust[0][i+1];
            }
            for(int i=1; i<=Aircleaner[Idx].y; i++){
                fine_dust[i-1][C-1]=fine_dust[i][C-1];
            }
            for(int i=C-1; i>1; i--){
                fine_dust[Aircleaner[Idx].y][i]=fine_dust[Aircleaner[Idx].y][i-1];
            }
            fine_dust[Aircleaner[Idx].y][1]=0;
        }
        else{
            for(int i=Aircleaner[Idx].y+1; i<R-1; i++){
                fine_dust[i][0]=fine_dust[i+1][0];
            }
            for(int i=0; i<C-1; i++){
                fine_dust[R-1][i]=fine_dust[R-1][i+1];
            }
            for(int i=R-1; i>=Aircleaner[Idx].y; i--){
                fine_dust[i][C-1]=fine_dust[i-1][C-1];
            }
            for(int i=C-1; i>1; i--){
                fine_dust[Aircleaner[Idx].y][i]=fine_dust[Aircleaner[Idx].y][i-1];
            }
            fine_dust[Aircleaner[Idx].y][1]=0;
        }
    }
}
void Output(){
    cout<<"\\\\\\\\"<<"\n";
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<fine_dust[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void Spread(int y, int x){
    int Temp=(fine_dust[y][x])/5;
    int cnt=0;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isinside(ny,nx)|| fine_dust[ny][nx]==-1)continue;
        cnt++;
        C_fine_dust[ny][nx]+=Temp;
    }
    fine_dust[y][x]-=Temp*cnt;
}
void Add(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            fine_dust[i][j]+=C_fine_dust[i][j];
            C_fine_dust[i][j]=0;
        }
    }
}
void Fine_Dust_Spread(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(fine_dust[i][j]==-1 || fine_dust==0)continue;
            Spread(i,j);
        }
    }
    Add();
}
void Solve(){
    for(int i=0; i<T ;i++){
        Fine_Dust_Spread();
        //Output();
        Air();
    }
    cout<<Count()<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}