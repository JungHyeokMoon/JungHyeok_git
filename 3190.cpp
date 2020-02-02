#include <bits/stdc++.h>
using namespace std;
int n,k,l;
int apple[100][100];
queue<pair<int,char>> direction;
//뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
queue<pair<int,int>> snake;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int L[4]={1,2,3,0};
int D[4]={3,0,1,2};
int ret=0;
void Input(){
    cin>>n;
    cin>>k;
    for(int i=0; i<k; i++){
        int y,x;
        cin>>y>>x;
        apple[y-1][x-1]=1; //사과의 위치는 1
    }
    cin>>l;
    for(int i=0; i<l; i++){
        int second;
        char direc;
        cin>>second>>direc;
        direction.push({second,direc}); //l왼쪽 , d오른쪽
    }
}
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n)
        return true;
    return false;
}
void Solve(){
    //뱀의 시작위치는 0,0
    apple[0][0]=2;
    snake.push({0,0});
    int hx=0,hy=0;
    int d=0;
    while(1){
        hy+=dy[d];
        hx+=dx[d];
        ret++;
        if(!isinside(hy,hx)||apple[hy][hx]==2){
            cout<<ret<<"\n";
            return ;
        }
        if(apple[hy][hx]==0){
            int tale_y=snake.front().first;
            int tale_x=snake.front().second;
            snake.pop();
            apple[tale_y][tale_x]=0;
        }
        apple[hy][hx]=2;
        snake.push({hy,hx});
        if(ret==direction.front().first){
            if(direction.front().second=='L'){
                d=L[d];
            }
            else if(direction.front().second=='D'){
                d=D[d];
            }
            direction.pop();
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}