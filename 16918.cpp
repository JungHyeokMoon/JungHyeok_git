#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<char>> MAP;
// vector<pair<int,int>> bomb;
set<pair<int,int>> prevBomb;
set<pair<int,int>> curBomb;
int r,c,n;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
bool IsInside(int y, int x){
    if(y>=0 && y<r && x>=0 && x<c)
        return true;
    return false;
}
void Init(){
    cin>>r>>c>>n;
    MAP.resize(r,vector<char>(c));
    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            MAP[i][j]=temp[j];
            if(temp[j]=='O')
                prevBomb.insert({i,j});
        }
    }

    // for(auto i : MAP){
    //     for(auto j : i){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }

    // for(auto i : bomb)
    //     cout<<i.first<<" "<<i.second<<endl;
}
void Output(){
    for(auto & i :MAP){
        for(auto & j :i){
            cout<<j;
        }
        cout<<endl;
    }
}
void fillBomb(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(MAP[i][j]=='.'){
                curBomb.insert({i,j});
                MAP[i][j]='O';
            }
        }
    }
}
void Boom(){
    for(auto i :prevBomb){
        int hy=i.first;
        int hx=i.second;
        MAP[hy][hx]='.';
        if(curBomb.find({hy,hx})!=curBomb.end())
            curBomb.erase({hy,hx});
        for(int j=0; j<4; j++){
            int ny=hy+dir[j].first;
            int nx=hx+dir[j].second;
            if(!IsInside(ny,nx))continue;
            MAP[ny][nx]='.';
            if(curBomb.find({ny,nx})!=curBomb.end())
                curBomb.erase({ny,nx});
        }
    }
    prevBomb.clear();
    prevBomb=curBomb;
    curBomb.clear();
}
void Solve(){
    if(n==1){
        Output();
        return ;
    }
    
    for(int i=2 ;i<=n; i++){
        if((i & 1)==0)
            fillBomb();
        else{
            Boom();
        }
    }

    Output();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    
    return 0;
}