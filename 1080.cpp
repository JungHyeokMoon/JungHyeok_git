#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;
vector<vector<int>> A,B;
int ret=0;
bool answerCheck(vector<vector<int>> & A, vector<vector<int>> & B){
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]!=B[i][j])return false;
        }
    }
    return true;
}
void Init(vector<vector<int>> & matrix){
    matrix.resize(n);
    for(int i=0 ;i<n; i++){
        matrix[i].resize(m);
    }
}
void SuvInput(vector<vector<int>> & matrix){
    for(int i=0; i<n; i++){
        string input;
        cin>>input;
        for(int j=0; j<m; j++){
            matrix[i][j]=input[j]-'0';
        }
    }
}
void Input(){
    cin>>n>>m;
    Init(A);
    Init(B);
    
    SuvInput(A);
    SuvInput(B);
    
}
void Turn(vector<vector<int>> &A,int y, int x){
    for(int i=y; i<y+3; i++){
        for(int j=x; j<x+3; j++){
            A[i][j]= !A[i][j];
        }
    }
    ret++;
}
void Solve(){
    if(n<3 && m<3){
        if(!answerCheck(A,B))cout<<-1<<endl;
        else cout<<0<<endl;
        return ;
    } //크기가 3*3보다작을때

    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=m-3; j++){
            if(A[i][j]!=B[i][j])Turn(A,i,j);
            
            if(answerCheck(A,B)){
                cout<<ret<<endl;
                return ;
            }
        }
    }

    if(!answerCheck(A,B))cout<<-1<<endl;
    else cout<<ret<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}