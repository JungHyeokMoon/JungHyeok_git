#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<vector<char>> MAP;
vector<pair<int,int>> candidate;
vector<bool> combi;
vector<pair<int,int>> teacher;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
void Init(){
    cin>>n;
    MAP.resize(n,vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>MAP[i][j];
            if(MAP[i][j]=='X')
                candidate.push_back({i,j});
            else if(MAP[i][j]=='T')
                teacher.push_back({i,j});
        }
    }
}
bool Isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n)
        return true;
    return false;
}
bool Watch(int y, int x,vector<vector<char>> & CMAP,int direction){
    int hy=y;
    int hx=x;
    while(1){
        int ny=hy+dir[direction].first;
        int nx=hx+dir[direction].second;
        if(!Isinside(ny,nx))return true;
        if(CMAP[ny][nx]=='O')return true;
        if(CMAP[ny][nx]=='S')return false;
        hy=ny;
        hx=nx;
    }
}

bool Avoid(vector<bool> &combi){
    vector<vector<char>> CMAP=MAP;
    for(int i=0; i<combi.size(); i++){
        if(combi[i]==false)
            CMAP[candidate[i].first][candidate[i].second]='O';
    }

    for(auto i : teacher){
        int ty=i.first;
        int tx=i.second;
        for(int j=0; j<4; j++)
            if(!Watch(ty,tx,CMAP,j))return false;
    }
    return true;
}
void Solve(){
    combi.resize(candidate.size(),true);
    fill(combi.begin(),combi.begin()+3,false);
    do{
        if(Avoid(combi)){
            cout<<"YES"<<endl;
            return ;
        }
    }while(next_permutation(combi.begin(),combi.end()));
    cout<<"NO"<<endl;
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