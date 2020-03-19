#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<char> > arr;

set<string> Set;

const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
bool isinside(int y, int x){
    if(y>=0 && y<5 && x>=0 && x<5){
        return true;
    }
    return false;
}
void Input(){
    arr.resize(5);
    for(int i=0; i<5; i++){
        arr[i].resize(5);
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }
}
void dfs(pair<int,int> hc,string str){
    if(str.size()==6){
        Set.insert(str);
        return ;
    }
    
    for(int i=0; i<4; i++){
        int ny=hc.first+dy[i];
        int nx=hc.second+dx[i];
        
        if(!isinside(ny,nx))continue;
        
        
        dfs({ny,nx},str+arr[ny][nx]);
        
    }
}

void Solve(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dfs( {i,j},"");
        }
    }
    cout<<Set.size()<<endl;
    
    // for(set<string>::iterator it=Set.begin() ; it!=Set.end(); it++){
    //     cout<<*it<<endl;
    // }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}