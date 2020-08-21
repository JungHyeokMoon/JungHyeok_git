// #include <bits/stdc++.h>
// using namespace std;

// int Maze[5][5][5];
// int C_Maze[5][5][5];
// int dz[6]={1,-1,0,0,0,0};
// int dy[6]={0,0,1,0,-1,0};
// int dx[6]={0,0,0,1,0,-1};
// bool isvisited[5][5][5];
// int Maze_order[5];
// int Turn_order[5];
// bool Select[5];
// int ret=987654321;
// bool isinside(int z, int y, int x){
//     if(z>=0 && z<5 && y>=0 && y<5 && x>=0 &&x<5){
//         return true;
//     }
//     return false;
// }


// int bfs(){
//     queue<pair<pair<int,int>,pair<int,int>>>q;
//     q.push({{0,0},{0,0}});
//     isvisited[0][0][0]=true;

//     while(!q.empty()){
//         int hz=q.front().first.first;
//         int hy=q.front().first.second;
//         int hx=q.front().second.first;
//         int cnt=q.front().second.second;

//         q.pop();
//         if(hz==4 && hy==4 && hx==4){
//             return cnt;
//         }
//         for(int i=0; i<6; i++){
//             int nz=hz+dz[i];
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(nz,ny,nx))continue;
//             if(isvisited[nz][ny][nx])continue;
//             if(C_Maze[nz][ny][nx]==1){
//                 q.push({{nz,ny},{nx,cnt+1}});
//                 isvisited[nz][ny][nx]=true;
//             }
//         }
//     }
//     return -1;
// }
// void Make_Maze(){
//     for(int i=0; i<5; i++){
//         for(int j=0; j<5; j++){
//             for(int k=0; k<5; k++){
//                 C_Maze[i][j][k]=-1;
//             }
//         }
//     } //초기화작업

//     for(int i=0; i<5; i++){
//         int idx=Maze_order[i];
//         int Turn=Turn_order[i];
//         if(Turn==0){
//             for(int x=0; x<5 ;x++){
//                 for(int y=0; y<5 ; y++){
//                     C_Maze[i][x][y]=Maze[idx][x][y];
//                 }
//             }
//         }//그대로
//         else if(Turn==1){
//             for(int x=0; x<5 ; x++){
//                 for(int y=0; y<5; y++){
//                     C_Maze[i][x][y]=Maze[idx][y][4-x];
//                 }
//             }
//         }//90도회전
//         else if(Turn==2){
//             for(int x=0; x<5; x++){
//                 for(int y=0; y<5; y++){
//                     C_Maze[i][x][y]=Maze[idx][4-x][4-y];
//                 }
//             }
//         }//180도회전
//         else{
//             for(int x=0; x<5; x++){
//                 for(int y=0; y<5; y++){
//                     C_Maze[i][x][y]=Maze[idx][4-y][x];
//                 }
//             }
//         }
//     }
// }
// void Make_Maze_Turn_Order(int cnt){
//     if(cnt==5){
//         Make_Maze();
//         if(C_Maze[0][0][0]==1 && C_Maze[4][4][4]==1){
//             memset(isvisited,false,sizeof(isvisited));
//             int result=bfs();
//             if(result!=-1){
//                 ret=min(ret,result);
//             }
//         }
//         return ;
//     }

//     for(int Turn=0; Turn<4; Turn++){
//         Turn_order[cnt]=Turn;
//         Make_Maze_Turn_Order(cnt+1);
//     }
// }
// void Make_Maze_Order(int cnt){
//     if(cnt==5){
//         Make_Maze_Turn_Order(0);
//         return ;
//     }

//     for(int i=0; i<5 ; i++){
//         if(Select[i])continue;
//         Select[i]=true;
//         Maze_order[i]=cnt;
//         Make_Maze_Order(cnt+1);
//         Select[i]=false;
//         Maze_order[i]=-1;
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     for(int i=0; i<5; i++){
//         for(int j=0; j<5; j++){
//             for(int k=0; k<5; k++){
//                 cin>>Maze[i][j][k];
//             }
//         }
//     }//0은 참가자가 들어갈수없는칸 , 1 은 참가자가 들어갈수 있는칸
//     for(int i=0; i<5; i++){
//         Maze_order[i]=-1;
//         Turn_order[i]=-1;
//     }
//     Make_Maze_Order(0);
//     if(ret==987654321){
//         cout<<-1<<"\n";
//     }
//     else{
//         cout<<ret<<"\n";
//     }
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<vector<vector<int>>> MAP;
vector<int> idx;
vector<int> rotation;
int ret=1e9;
void Init(){
    for(int i=0; i<5; i++){
        vector<vector<int>> temp(5,vector<int>(5)); //0은 들어갈수 없는칸,1은참가자가 들어갈수 있는칸
        idx.push_back(i);
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                cin>>temp[j][k];
        MAP.push_back(temp);
    }

    for(int i=0; i<4; i++)
        for(int j=0; j<5; j++)
            rotation.push_back(i);

}

tuple<int,int,int> dir[6]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
bool IsInside(int z, int y, int x){
    if(z>=0 && z<5 && y>=0 && y<5 && x>=0 && x<5)
        return true;
    return false;
}
void Rotate(vector<vector<vector<int>>> &MAP,int idx, int angle){
    vector<vector<int>> temp(5,vector<int>(5));
    if(angle==1){
        for(int i=0 ;i<5; i++)
            for(int j=0; j<5; j++)
                temp[i][j]=MAP[idx][5-1-j][i];
    }
    else if(angle==2){
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                temp[i][j]=MAP[idx][5-1-i][5-1-j];
    }
    else if(angle==3){
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                temp[i][j]=MAP[idx][j][5-1-i];
    }

    if(angle!=0){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                MAP[idx][i][j]=temp[i][j];
            }
        }
    }
}
void bfs(vector<vector<vector<int>>> &MAP){
    if(MAP[0][0][0]==0 || MAP[4][4][4]==0)
        return;

    vector<vector<int>> temp(5,vector<int>(5,-1));
    vector<vector<vector<int>>> dist;
    for(int i=0; i<5; i++)
        dist.push_back(temp); //dist 배열 초기화

    dist[0][0][0]=0;
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));

    while(!q.empty()){
        int hz,hy,hx;
        tie(hz,hy,hx)=q.front();
        q.pop();

        if(hz==4 && hy==4 && hx==4){
            ret=min(ret,dist[hz][hy][hx]);
            return ;
        }

        for(int i=0; i<6; i++){
            int nz=hz+get<0>(dir[i]);
            int ny=hy+get<1>(dir[i]);
            int nx=hx+get<2>(dir[i]);

            if(!IsInside(nz,ny,nx))continue;
            if(dist[nz][ny][nx]!=-1)continue;
            if(MAP[nz][ny][nx]==1){
                q.push(make_tuple(nz,ny,nx));
                dist[nz][ny][nx]=dist[hz][hy][hx]+1;
            }
        }
    }

}
void Maze()
{
    vector<vector<vector<int>>> C_MAP;
    for(int i=0; i<5; i++){
        C_MAP.push_back(MAP[idx[i]]);
        Rotate(C_MAP,i,rotation[i]);
    } //이번 시뮬레이션에 돌릴 C_MAP
    // cout<<"-------------------------------------------"<<endl;
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         for(int k=0; k<5; k++){
    //             cout<<C_MAP[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    // cout<<"-------------------------------------------"<<endl;
    bfs(C_MAP);
}

void Solve(){
    do{
        do{
            Maze();  
            reverse(rotation.begin()+5,rotation.end());
        }while(next_permutation(rotation.begin(), rotation.end()));
    }while(next_permutation(idx.begin(),idx.end()));

    if(ret==1e9)
        cout<<-1<<endl;
    else
        cout<<ret<<endl;
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