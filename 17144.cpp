// #include <bits/stdc++.h>
// using namespace std;

// int R,C,T;
// int fine_dust[50][50];
// int C_fine_dust[50][50];
// int dy[4]={-1,0,1,0};
// int dx[4]={0,1,0,-1};
// bool isinside(int y, int x){
//     if(y>=0 && y<R && x>=0 &&x<C){
//         return true;
//     }
//     return false;
// }
// typedef struct pos{
//     int y,x;
// }pos;
// pos Aircleaner[2];
// int Count(){
//     int sum=0;
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             if(fine_dust[i][j]==-1)continue;
//             sum+=fine_dust[i][j];
//         }
//     }
//     return sum;
// }
// void Input(){
//     cin>>R>>C>>T;
//     int Idx=0;
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             cin>>fine_dust[i][j];
//             if(fine_dust[i][j]==-1){
//                 Aircleaner[Idx].y=i;
//                 Aircleaner[Idx].x=j;
//                 Idx++;
//             }
//         }
//     }
// }
// void Air(){
//     for(int Idx=0; Idx<2; Idx++){
//         if(Idx==0){
//             for(int i=Aircleaner[Idx].y-1; i>0 ; i--){
//                 fine_dust[i][0]=fine_dust[i-1][0];
//             }
//             for(int i=0; i<C-1; i++){
//                 fine_dust[0][i]=fine_dust[0][i+1];
//             }
//             for(int i=1; i<=Aircleaner[Idx].y; i++){
//                 fine_dust[i-1][C-1]=fine_dust[i][C-1];
//             }
//             for(int i=C-1; i>1; i--){
//                 fine_dust[Aircleaner[Idx].y][i]=fine_dust[Aircleaner[Idx].y][i-1];
//             }
//             fine_dust[Aircleaner[Idx].y][1]=0;
//         }
//         else{
//             for(int i=Aircleaner[Idx].y+1; i<R-1; i++){
//                 fine_dust[i][0]=fine_dust[i+1][0];
//             }
//             for(int i=0; i<C-1; i++){
//                 fine_dust[R-1][i]=fine_dust[R-1][i+1];
//             }
//             for(int i=R-1; i>=Aircleaner[Idx].y; i--){
//                 fine_dust[i][C-1]=fine_dust[i-1][C-1];
//             }
//             for(int i=C-1; i>1; i--){
//                 fine_dust[Aircleaner[Idx].y][i]=fine_dust[Aircleaner[Idx].y][i-1];
//             }
//             fine_dust[Aircleaner[Idx].y][1]=0;
//         }
//     }
// }
// void Output(){
//     cout<<"\\\\\\\\"<<"\n";
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             cout<<fine_dust[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
// void Spread(int y, int x){
//     int Temp=(fine_dust[y][x])/5;
//     int cnt=0;
//     for(int i=0; i<4; i++){
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         if(!isinside(ny,nx)|| fine_dust[ny][nx]==-1)continue;
//         cnt++;
//         C_fine_dust[ny][nx]+=Temp;
//     }
//     fine_dust[y][x]-=Temp*cnt;
// }
// void Add(){
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             fine_dust[i][j]+=C_fine_dust[i][j];
//             C_fine_dust[i][j]=0;
//         }
//     }
// }
// void Fine_Dust_Spread(){
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             if(fine_dust[i][j]==-1 || fine_dust==0)continue;
//             Spread(i,j);
//         }
//     }
//     Add();
// }
// void Solve(){
//     for(int i=0; i<T ;i++){
//         Fine_Dust_Spread();
//         //Output();
//         Air();
//     }
//     cout<<Count()<<"\n";
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     Input();
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int r,c,t;
vector<vector<int>> MAP;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
pair<int,int> airCleaner[2];
// set<pair<int,int>> dustSet;
bool IsInside(int y, int x){
    if(y>=0 && y<r && x>=0 && x<c)
        return true;
    return false;
}
void Test(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<MAP[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Init(){
    cin>>r>>c>>t;
    MAP.resize(r,vector<int>(c));
    int temp=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>MAP[i][j];
            if(MAP[i][j]==-1)
                airCleaner[temp++]={i,j};
            // else if(MAP[i][j]!=-1 && MAP[i][j]!=0)
            //     dustSet.insert({i,j});
        }
    }
}
void DustDiffusion(){
    vector<tuple<int,int,int>> tempV;
    // for(set<pair<int,int>>::iterator it=dustSet.begin(); it!=dustSet.end(); it++){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(MAP[i][j]!=-1 && MAP[i][j]!=0){
                    // int hy=(*it).first;
                    int hy=i;
                    // int hx=(*it).second;
                    int hx=j;

                    int diffusionRoom=0;
                    int dust=(MAP[hy][hx]/5);
                    for(int i=0; i<4; i++){
                        int ny=hy+dir[i].first;
                        int nx=hx+dir[i].second;

                        if(!IsInside(ny,nx))continue;
                        if(MAP[ny][nx]==-1)continue;
                        diffusionRoom++;
                        tempV.push_back(make_tuple(ny,nx,dust));
                    }
                    MAP[hy][hx]=MAP[hy][hx]-(diffusionRoom*dust);
                }
            }
        }
        
    // }
    int length=tempV.size();
    for(int i=0; i<length; i++){
        int y,x,dust;
        tie(y,x,dust)=tempV[i];
        MAP[y][x]+=dust;
        // dustSet.insert({y,x});
    }
    
}
void AirClean(){
    //위
    int uy=airCleaner[0].first, ux=airCleaner[0].second;
    int dy=airCleaner[1].first, dx=airCleaner[1].second;
    for(int i=uy-1; i>=1; i--)
        MAP[i][0]=MAP[i-1][0];
    
    for(int i=0; i<=c-2; i++)
        MAP[0][i]=MAP[0][i+1];
    
    for(int i=0; i<=uy-1; i++)
        MAP[i][c-1]=MAP[i+1][c-1];
    
    for(int i=c-1; i>=2; i--)
        MAP[uy][i]=MAP[uy][i-1];
    MAP[uy][1]=0;
    
    // //아래
    for(int i=dy+1; i<=r-2; i++)
        MAP[i][0]=MAP[i+1][0];
    
    for(int i=0; i<=c-2; i++)
        MAP[r-1][i]=MAP[r-1][i+1];
    
    for(int i=r-1; i>=dy+1; i--)
        MAP[i][c-1]=MAP[i-1][c-1];
    
    for(int i=c-1; i>=2; i--)
        MAP[dy][i]=MAP[dy][i-1];
    MAP[dy][1]=0;
    
}
int Output(){
    int ret=0;
    for(int i=0 ;i<r; i++)
        for(int j=0; j<c; j++)
            if(MAP[i][j]!=-1)
                ret+=MAP[i][j];

    return ret;
}
void Solve(){
    for(int i=0; i<t; i++){
        DustDiffusion();
        // cout<<"-----------------DustDiffusion-------------"<<endl;
        // Test();
        AirClean();
        // cout<<"-----------------AirClean------------------"<<endl;
        // Test();
    } 
    cout<<Output()<<endl;
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