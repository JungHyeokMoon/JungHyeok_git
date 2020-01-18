#include <bits/stdc++.h>
using namespace std;
int n;
int chess[10][10];
bool isvisited[10][10];
bool color[10][10];
int dy[2]={-1,-1};
int dx[2]={-1,1};
int sum=0;
//int res[2];
int res=-987654321;
bool isok(int y, int x){
    
    for(int i=0; i<2; i++){
        int ny=y;
        int nx=x;
        while(1){
            if(ny<0|| nx<0 || ny>=n || nx>=n)break;
            if(isvisited[ny][nx])return false;
            ny+=dy[i];
            nx+=dx[i];
        }
    }
    return true;
}
void dfs(int index, bool b_w, int cnt){

    for(int i=index+1; i<n*n; i++){
        int y=i/n;
        int x=i%n;
        
        if(color[y][x]!=b_w || chess[y][x]==0||!isok(y,x) )continue;

        isvisited[y][x]=true;
        dfs(i,b_w,cnt+1);
        isvisited[y][x]=false;
    }
    //res[b_w ? true : false]=max(res[b_w? true: false],cnt);
    res=max(res,cnt);
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>chess[i][j];
            if((i+j)%2==0)color[i][j]=0; //black
            else color[i][j]=1; //white
            //color[i][j] = (i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0);

        }
    } //놓을수 있는곳 1, 놓을수 없는곳 0 
    /*cout<<"\\\\\\\\\\"<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            cout<<color[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    dfs(-1,0,0);
    sum+=res;
    res=0;
    dfs(-1,1,0);
    sum+=res;
    cout<<sum<<"\n";
    return 0;
}