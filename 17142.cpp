// #include <bits/stdc++.h>	
// #define endl "\n"	
// using namespace std;
// int n,m;
// vector<vector<int>> MAP;
// vector<pair<int,int>> VirusInput;
// const int dy[4]={-1,0,1,0};
// const int dx[4]={0,-1,0,1};
// vector<bool> Combivisited;
// vector<pair<int,int>> virus;
// vector<vector<int>> Time;

// int Ret=1e9;
// int EmptyRoomcount=0;
// bool isinside(int y,int x){
//     if(y>=0 && y<n && x>=0 && x<n){
//         return true;
//     }
//     return false;
// }
// void BFS(){
//     queue<pair<int,int>> q;
//     for(int i=0; i<n; i++){
//         fill(Time[i].begin(),Time[i].begin()+n,-1);
//     }
//     int InfectRoom=0;
//     for(int i=0; i<virus.size(); i++){
//         q.push({virus[i].first,virus[i].second});
//         Time[virus[i].first][virus[i].second]=0;
//     }
    
//     int TempTime=0;
//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;
//         q.pop();
        
//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;
//             if(MAP[ny][nx]==1){
//                 continue;
//             }
//             if(Time[ny][nx]==-1){
//                 Time[ny][nx]=Time[hy][hx]+1;
//                 if(MAP[ny][nx]==0){
//                     TempTime=Time[ny][nx];
//                     InfectRoom++;
//                 }
//                 q.push({ny,nx});
//             }   
//         }
//     }
//     if(InfectRoom==EmptyRoomcount){
//         Ret=min(Ret,TempTime);
//     }
// }
// void Make_Combi(int depth ,int idx){
//     if(depth==m){
//         BFS();
//         return ;
//     }
//     for(int i=idx; i<VirusInput.size(); i++){
//         if(!Combivisited[i]){
//             Combivisited[i]=true;
//             virus.push_back({VirusInput[i].first,VirusInput[i].second});
//             Make_Combi(depth+1,i+1);
//             virus.pop_back();
//             Combivisited[i]=false;
//         }
//     }
// }
// void Input(){
//     cin>>n>>m;
//     MAP.resize(n,vector<int>(n));
//     Time.resize(n,vector<int>(n));
    
//     for(int i=0; i<n ; i++){
//         for(int j=0; j< n ; j++){
//             cin>>MAP[i][j];
//             if(MAP[i][j]==2){
//                 VirusInput.push_back({i,j});
//             }
//             else if(MAP[i][j]==0){
//                 EmptyRoomcount++;
//             }
//         }
//     }
//     Combivisited.resize(VirusInput.size(),false);
// }

// //m개만큼조합을만들어야함
// void Solve(){
//     Make_Combi(0,0);
//     if(Ret==1e9){
//         cout<<-1<<endl;
//     }else{
//         cout<<Ret<<endl;
//     }
// }
// int main(){	
//     ios_base::sync_with_stdio(0);	
//     cin.tie(0);	
//     cout.tie(0);	
//     Input();
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<vector<int>> MAP;
vector<pair<int,int>> virus;
vector<bool> combi;
int length;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
int ret=1e9;

bool isInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<n)
        return true;
    return false;
}
int emptyRoom=0;
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<int>(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>MAP[i][j];
            if(MAP[i][j]==2)
                virus.push_back({i,j});
            else if(MAP[i][j]==0)
                emptyRoom++;
        }
    }
    length=virus.size();
    combi.resize(length,true);
    fill(combi.begin(),combi.begin()+m,false);
}

void bfs(){
    vector<vector<int>> dist(n,vector<int>(n,-1));
    queue<pair<int,int>> q;
    int infect=0;
    int times=0;
    for(int i=0; i<length; i++){
        if(combi[i]==false){
            q.push(virus[i]);
            dist[virus[i].first][virus[i].second]=0;
        }
    }

    while(!q.empty()){
        int hy=q.front().first;
        int hx=q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;

            if(!isInside(ny,nx))continue;
            if(dist[ny][nx]!=-1)continue;
            if(MAP[ny][nx]==1)continue;

            q.push({ny,nx});
            dist[ny][nx]=dist[hy][hx]+1;
            if(MAP[ny][nx]==0){
                times=dist[ny][nx];
                infect++;
            }            
            
        }
    }
    if(infect==emptyRoom)
        ret=min(ret,times);
    
}
void Solve(){
    do{
        bfs();
    }while(next_permutation(combi.begin(),combi.end()));
    if(ret==1e9)cout<<-1<<endl;
    else cout<<ret<<endl;
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

