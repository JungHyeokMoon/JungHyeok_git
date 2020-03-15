#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
char castle[50][50];
int n,m;
int ret=0;
vector<bool> row,col;
void Input(){
    cin>>n>>m;
    row.resize(n,false);
    col.resize(m,false);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>castle[i][j];
            if(castle[i][j]=='X'){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    
}
void Solve(){
    int temp1=0;
    int temp2=0;
    for(int i=0; i<n; i++){
        if(!row[i])temp1++;
    }
    for(int i=0; i<m; i++){
        if(!col[i])temp2++;
    }

    cout<<max(temp1,temp2)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}