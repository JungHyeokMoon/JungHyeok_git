#include <bits/stdc++.h>
using namespace std;
int sdoku[9][9];
bool Row[9][9];
bool Col[9][9];
bool Squre[9][9];

void output(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<sdoku[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(int c){
    int y=c/9;
    int x=c%9;
    if(c==81){
        //cout<<"\n";
        output();
        exit(0);
    }
    if(!sdoku[y][x]){
        for(int i=1; i<=9; i++){
            if(!Row[y][i]&&!Col[x][i]&&!Squre[(y/3)*3+x/3][i]){
                Row[y][i]=true;
                Col[x][i]=true;
                Squre[(y/3)*3+x/3][i]=true;
                sdoku[y][x]=i;
                solve(c+1);
                Row[y][i]=false;
                Col[x][i]=false;    
                Squre[(y/3)*3+x/3][i]=false;
                sdoku[y][x]=0;
            }
        }
    }
    else solve(c+1);
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sdoku[i][j];
            if(sdoku[i][j]!=0){
                Row[i][sdoku[i][j]]=true;
                Col[j][sdoku[i][j]]=true;
                Squre[(i/3)*3+(j/3)][sdoku[i][j]]=true;
            }
        }
    }
    
    solve(0);



    return 0;

}