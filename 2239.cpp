#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int puzzle[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];
void Input(){
    for(int i=0; i<9; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<9; j++){
            int inputnum=temp[j]-'0';
            puzzle[i][j]=inputnum;
            if(inputnum!=0){
                row[i][puzzle[i][j]]=true; //i번째가로줄에는 입력받은값이 이미존재
                col[j][puzzle[i][j]]=true; //j번째 세로열에는 입력받은값이 이미존재
                square[(i/3)*3+(j/3)][puzzle[i][j]]=true;
            }
        }
    }
}

void Output(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<puzzle[i][j];
        }
        cout<<endl;
    }
}
void backtracking(int cnt){
    if(cnt==81){
        Output();
        exit(0);
    }
    int y=cnt/9;
    int x=cnt%9;
    if(!puzzle[y][x]){//puzzle이 0인경우
        for(int i=1; i<=9; i++){
            if(row[y][i])continue;
            if(col[x][i])continue;
            if(square[(y/3)*3+(x/3)][i])continue;
            row[y][i]=true;
            col[x][i]=true;
            square[(y/3)*3+(x/3)][i]=true;
            puzzle[y][x]=i;
            backtracking(cnt+1);
            row[y][i]=false;
            col[x][i]=false;
            square[(y/3)*3+(x/3)][i]=false;
            puzzle[y][x]=0;

        }
    }   
    else{
        backtracking(cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    backtracking(0);
    return 0;
}