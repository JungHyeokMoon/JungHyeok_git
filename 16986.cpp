#include <bits/stdc++.h>
using namespace std;
int n,k;
int match[10][10];
int JKM[3][20];
bool Select[10];
int win[3]; //0 지우 1 경희 2민호
int turn[3];
int ans=0;

void Input(){
    cin>>n>>k; //손동작수 ,필요한승수
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>match[i][j]; //2이면 i가 j를 이김 ,1이면 비기고 , 0이면 진다
        }
    }
    for(int i=1; i<3; i++){
        for(int j=0; j<20; j++){
            cin>>JKM[i][j];
        }
    }
}

void dfs(int p1, int p2){
    if(win[0]==k){
        ans=1;
        return; 
    }
    if(win[1]==k||win[2]==k){
        return;
    }
    if(turn[0]>n||ans==1){
        return ;
    }
    int winner;
    int turn1=turn[p1];
    int turn2=turn[p2];

    int n1=JKM[p1][turn1]; 
    int n2=JKM[p2][turn2];

    if(match[n1][n2]==2){
        winner=p1;
    }
    else if(match[n1][n2]==0){
        winner=p2;
    }
    else {
        if(p1<p2){
            winner=p2;
        }
        else{
            winner=p1;
        }
    }

    turn[p1]++;
    turn[p2]++;
    win[winner]++;
    dfs(winner,3-(p1+p2));
    win[winner]--;
    turn[p1]--;
    turn[p2]--;

}
void Make_Order(int cnt){
    if(cnt==10){
        dfs(0,1);
        return;
    }
    for(int i=1; i<=n; i++){
        if(Select[i])continue;
        Select[i]=true;
        JKM[0][cnt]=i;
        Make_Order(cnt+1);
        JKM[0][cnt]=-1;
        Select[i]=false;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    cout<<ans<<"\n";
    return 0;
}