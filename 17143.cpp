// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int R,C,M;
// typedef struct shark{
//     int speed;
//     int direction;
//     int Size;
// }shark;
// vector<shark> Sv [100][100];
// int Turn_Direction(int d){
//     if(d==0){//위면
//         return 1;//아래
//     }else if(d==1){//아래면
//         return 0;//위
//     }
//     else if(d==2){//오른쪽이면
//         return 3;//왼쪽
//     }
//     else {
//         return 2;//왼쪽이면 오른쪽
//     }
// }
// const int dy[4]={-1,1,0,0}; //위 아래 오른쪽 왼쪽
// const int dx[4]={0,0,1,-1};
// void Input(){
//     cin>>R>>C>>M;
//     for(int i=0; i<M ; i++){
//         int r,c,s,d,z;
//         cin>>r>>c>>s>>d>>z;
//         r--;
//         c--;
//         d--;
//         Sv[r][c].push_back({s,d,z});//speed , direction ,size를 각각 셀마다 넣어줌
//     }
// }
// void Output(){
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             if(Sv[i][j].size()==0) {cout<<"empty    ";}
//             else cout<<"(" <<Sv[i][j][0].speed<<" , "<<Sv[i][j][0].Size<<") ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }
// int ret=0;
// void Find_Shark(int x){

//     for(int i=0; i<R; i++){
//         if(Sv[i][x].size()==1){//한마리밖에없어야함 큰상어가 나머지상어들 다 잡아먹기때문에
//             ret+=Sv[i][x][0].Size;
//             Sv[i][x].pop_back();
//             return ;
//         }
//     }
// } 
// void Shark_Move(){ 
//     vector<pair<pair<int,int>,shark>> tempsv; //나중에 한꺼번에 처리하기위한 벡터
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             if(Sv[i][j].size()==0)continue;
//             shark temp=Sv[i][j][0]; //어짜피 한마리임 다같이모아놔서 큰놈이잡아먹게하기때문에
//             // cout<<"N : "<<N<<" shark y : "<<i<<" shark x : "<<j<<" shark speed : "<<temp.speed<<" shark d : "<<temp.direction<<" shark s: "<<temp.Size<<endl;
//             Sv[i][j].pop_back(); //임시로 빼내고 나서 클리어해줘야함
//             int hy=i;
//             int hx=j;
//             int hd=temp.direction;
//             int hspeed=temp.speed;
//             if(hd<2){
//                 hspeed=hspeed%(2*(R-1));
//                 while(hspeed--){
//                     if(hy==0 && hd==0){//위
//                         hd=Turn_Direction(hd);
//                     }
//                     if(hy==R-1 && hd==1){
//                         hd=Turn_Direction(hd);
//                     }
//                     hy+=dy[hd];
//                 }
//             }   
//             else{
//                 hspeed=hspeed%(2*(C-1));
//                 while(hspeed--){
//                     if(hx==0 && hd==3){
//                         hd=Turn_Direction(hd);
//                     }
//                     if(hx==C-1 && hd==2){
//                         hd=Turn_Direction(hd);
//                     }
//                     hx+=dx[hd];
//                 }
//             }
//             temp.direction=hd;
//             tempsv.push_back({{hy,hx},temp});
//         }
//     }


//     int tempsvlength=tempsv.size();
//     for(int i=0; i<tempsvlength; i++){
//         int y=tempsv[i].first.first;
//         int x=tempsv[i].first.second;
//         shark s=tempsv[i].second;
//         Sv[y][x].push_back(s);
//     }
// }
// bool compare(shark & a, shark & b){
//     if(a.Size<=b.Size){
//         return true;
//     }
//     return false;
// }
// void Shark_Each_Eat(){
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             if(Sv[i][j].size()==0)continue;
//             sort(Sv[i][j].begin(),Sv[i][j].end(),compare); //제일큰놈이 뒤로오게
//             shark temp=Sv[i][j].back();
//             Sv[i][j].clear(); //다없애주고
//             Sv[i][j].push_back(temp); //큰놈만넣어줌
//         } 
//     }
// }
// void Solve(){
//     for(int i=0; i<C; i++){
//         Find_Shark(i);
//         Shark_Move();
//         Shark_Each_Eat();
//         // Output();
//     }
//     cout<<ret<<endl;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Input();
//     Solve();
//     return 0;
// }
// //방향전환에서애먹었던문제 , 로직은 맞았다. 다른사람풀이를 보니 tempsv의 임시벡터에서 뿌려주는것은없고
// //넣을 칸에 이미 있는곳에 크기를 비교하는경우도 있다.


#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int r,c,m;
int ret=0;
class Shark{
    public:
        int s,d,z;

        Shark(int s,int d, int z):s(s),d(d),z(z){}
        Shark(){
            s=0;
            d=0;
            z=0;
        }
};

vector<vector<vector<Shark>>> MAP;

pair<int,int> dir[4]={{-1,0},{1,0},{0,1},{0,-1}};
void Init(){
    cin>>r>>c>>m;
    MAP.resize(r,vector<vector<Shark>>(c));
    for(int i=0; i<m; i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        MAP[r-1][c-1].push_back(Shark(s,d-1,z));
    }
}

bool Compare(Shark &a, Shark & b){
    return a.z<b.z ? true: false;
}
void Test(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(MAP[i][j].empty())
                cout<<"x x x"<<"|";
            else{
                int temp=MAP[i][j][0].d;
                if(temp==0)
                    cout<<"^"<<" ";
                else if(temp==1)
                    cout<<"v"<<" ";
                else if(temp==2)
                    cout<<">"<<" ";
                else
                    cout<<"<"<<" ";
                cout<<MAP[i][j][0].s<<" "<<MAP[i][j][0].z<<"|";
            }
        }
        cout<<endl;
        cout<<"------------------------------------"<<endl;
    }
    cout<<"ret: "<<ret<<endl;
}
void Fishing(int col){
    for(int j=0; j<r; j++){
        if(!MAP[j][col].empty()){
            ret+=MAP[j][col][0].z;
            MAP[j][col].pop_back();
            return;
        }
    }
}
void Shark_Move(){
    vector<tuple<int,int,Shark>> tempV;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!MAP[i][j].empty()){
                Shark tmpShk=MAP[i][j][0];
                MAP[i][j].pop_back();
                int hy=i;
                int hx=j;
                int hd=tmpShk.d;
                int hs=tmpShk.s;
                if(hd<2){ //위쪽 아래쪽
                    hs=hs%(2*(r-1));
                    while(hs--){
                        if(hy==0 && hd==0)
                            hd=1;
                        else if(hy==r-1 && hd==1)
                            hd=0;
                        hy+=dir[hd].first;
                    }
                    
                }else{
                    hs=hs%(2*(c-1));
                    while(hs--){
                        if(hx==0 && hd==3)
                            hd=2;
                        else if(hx==c-1 && hd==2)
                            hd=3;
                        hx+=dir[hd].second;
                    }
                    
                }
                tmpShk.d=hd;
                tempV.push_back(make_tuple(hy,hx,tmpShk));
            }
        }
    }

    int length=tempV.size();
    for(int i=0; i<length; i++){
        int y,x;
        Shark temp;
        tie(y,x,temp)=tempV[i];
        MAP[y][x].push_back(temp);
    }
}
void Each_Eating(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!MAP[i][j].empty()){
                sort(MAP[i][j].begin(),MAP[i][j].end(),Compare);
                Shark temp=MAP[i][j].back();
                MAP[i][j].clear();
                MAP[i][j].push_back(temp);
            }
        }
    }
}
void Solve(){
    // cout<<"----------------Original----------------"<<endl;
    // Test();
    for(int i=0; i<c; i++){
        Fishing(i);// 상어를 땅에서 제일 가까운애 잡는다.
        Shark_Move(); //상어 움직임
        Each_Eating(); //상어 자기들끼리 잡아먹음
        // Test();
    }
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