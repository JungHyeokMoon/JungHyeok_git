#include <bits/stdc++.h>
using namespace std;

int n,m;
int y,x;
int k;
int MAP[20][20];
int command[1000];
int dice[6]; //0이 위 2이동쪽 1가 북쪽 3가 서쪽 4가 남쪽 5이 아래쪽
bool isinside(int hx, int hy){
    if(hx>=0 && hx<n && hy>=0 && hy<m){
        return true;
    }
    return false;
}

void move(int cmd){
    //cout<<"cmd : "<<cmd<<" , "<<" x: "<<x<<" , "<<"y : "<<y<<"\n";
    if(cmd==1){
        y=y+1;
        if(!isinside(x,y)){
            y=y-1;
            return ;
        }
        int temp=dice[3];
        dice[3]=dice[5];
        dice[5]=dice[2];
        dice[2]=dice[0];
        dice[0]=temp;
    }//1동쪽
    else if(cmd==2){
        y=y-1;
        if(!isinside(x,y)){
            y=y+1;
            return ;
        }
        int temp=dice[2];
        dice[2]=dice[5];
        dice[5]=dice[3];
        dice[3]=dice[0];
        dice[0]=temp;
    }//2 서쪽
    else if(cmd==3){
        x=x-1;
        if(!isinside(x,y)){
            x=x+1;
            return ;
        }
        int temp=dice[0];
        dice[0]=dice[4];
        dice[4]=dice[5];
        dice[5]=dice[1];
        dice[1]=temp;
    }//3 북쪽
    else{
        x=x+1;
        if(!isinside(x,y)){
            x=x-1;
            return ;
        }
        int temp=dice[4];
        dice[4]=dice[0];
        dice[0]=dice[1];
        dice[1]=dice[5];
        dice[5]=temp;
    }//4 남쪽
    if(!MAP[x][y]){
        MAP[x][y]=dice[5];
    }
    else{
        dice[5]=MAP[x][y];
        MAP[x][y]=0;
    }
    cout<<dice[0]<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m>>x>>y>>k; //x가 북쪽에서 얼마나 떨어져있는지 y가 서쪽에서 얼마나 떨어져있는지
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cin>>MAP[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int num;
        cin>>num;
        move(num);
    }

    return 0;

}