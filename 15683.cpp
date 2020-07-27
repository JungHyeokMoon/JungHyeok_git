// #include <bits/stdc++.h>
// using namespace std;

// int n,m;
// vector<pair<pair<int,int>,int>> coordi;
// int camera[8][8];
// int C_camera[8][8];
// int Turn_order[8];
// bool isvisited[8][8];
// int ret=987654321;
// void copy_map(){
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<m; j++){
//             C_camera[i][j]=camera[i][j];
//         }
//     }
// }
// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 &&x<m){
//         return true;
//     }
//     return false;
// }
// int brute_force(){
//     for(int i=0; i<coordi.size(); i++){
//         int Turn=Turn_order[i];
//         int hy=coordi[i].first.first;
//         int hx=coordi[i].first.second;
//         int camerakind=coordi[i].second;
//         if(camerakind==1){
//             if(Turn==0){//오른쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx]!=0)continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else if(Turn==1){
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }//아래쪽
//             }else if(Turn==2){//왼쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else{//위쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }

//         }
//         else if(camerakind==2){
//             if(Turn==0|| Turn==2){
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx]!=0)continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }//오른쪽
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }//왼쪽
//             }//양옆
//             else{
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }//아래쪽
//             }//위아래
//         }
//         else if(camerakind==3){
//             if(Turn==0){//위 오른쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else if(Turn==1){//오른, 아래쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else if(Turn==2){ //아래쪽, 왼쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else{//왼쪽, 위쪽
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }
//         }
//         else if(camerakind==4){
//             if(Turn==0){//왼 위 오른
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;//
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else if(Turn==1){//위 오른 아래
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else if(Turn==2){//오른 아래 왼
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hx++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }else{//아래 왼 위
//                 int Temp_hy=hy;
//                 int Temp_hx=hx;
//                 while(1){
//                     Temp_hy++;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hx--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//                 Temp_hy=hy;
//                 Temp_hx=hx;
//                 while(1){
//                     Temp_hy--;
//                     if(!isinside(Temp_hy,Temp_hx))break;
//                     if(C_camera[Temp_hy][Temp_hx]==6)break;
//                     if(C_camera[Temp_hy][Temp_hx])continue;
//                     C_camera[Temp_hy][Temp_hx]=7;
//                 }
//             }
//         }
//         else{
//             int Temp_hy=hy;
//             int Temp_hx=hx;
//             while(1){
//                 Temp_hy++;
//                 if(!isinside(Temp_hy,Temp_hx))break;
//                 if(C_camera[Temp_hy][Temp_hx]==6)break;
//                 if(C_camera[Temp_hy][Temp_hx])continue;
//                 C_camera[Temp_hy][Temp_hx]=7;
//             }
//             Temp_hy=hy;
//             Temp_hx=hx;
//             while(1){
//                 Temp_hx--;
//                 if(!isinside(Temp_hy,Temp_hx))break;
//                 if(C_camera[Temp_hy][Temp_hx]==6)break;
//                 if(C_camera[Temp_hy][Temp_hx])continue;
//                 C_camera[Temp_hy][Temp_hx]=7;
//             }
//             Temp_hy=hy;
//             Temp_hx=hx;
//             while(1){
//                 Temp_hy--;
//                 if(!isinside(Temp_hy,Temp_hx))break;
//                 if(C_camera[Temp_hy][Temp_hx]==6)break;
//                 if(C_camera[Temp_hy][Temp_hx])continue;
//                 C_camera[Temp_hy][Temp_hx]=7;
//             }
//             Temp_hy=hy;
//             Temp_hx=hx;
//             while(1){
//                 Temp_hx++;
//                 if(!isinside(Temp_hy,Temp_hx))break;
//                 if(C_camera[Temp_hy][Temp_hx]==6)break;
//                 if(C_camera[Temp_hy][Temp_hx])continue;
//                 C_camera[Temp_hy][Temp_hx]=7;
//             }
//         }//turn 노상관
//     }

//     int count=0;
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<m; j++){
//             if(C_camera[i][j]==0){
//                 count++;
//             }
//         }
//     }
//     //cout<<count<<"\n";
//     return count;
// }
// void make_Turn_order(int cnt){
//     if(cnt==coordi.size()){
//         memset(isvisited,false,sizeof(isvisited));
//         copy_map();
//         int size=brute_force();
//         ret=min(ret,size);

//         return ;
//     }
//     for(int Turn=0; Turn<4; Turn++){
//         Turn_order[cnt]=Turn;
//         make_Turn_order(cnt+1);
//     } //0오른쪽 1 아래쪽 2 왼쪽 3 위쪽
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin>>n>>m;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>camera[i][j];
//             if(camera[i][j]>=1 && camera[i][j]<=5){
//                 coordi.push_back({{make_pair(i,j)},camera[i][j]});
//             }//카메라종류 0은 빈칸 6은벽 12345 카메라종류
//         }
//     }

//     make_Turn_order(0);

//     cout<<ret<<"\n";

//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<vector<int>> MAP;
vector<vector<int>> C_MAP;
vector<pair<pair<int, int>, pair<int, int>>> camera;
int ret = 1e9;
int rotation = 1;

void Output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << C_MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void multiplyRotation(int cameraKind)
{
    if (cameraKind == 1)
        rotation *= 4;
    else if (cameraKind == 2)
        rotation *= 2;
    else if (cameraKind == 3)
        rotation *= 4;
    else if (cameraKind == 4)
        rotation *= 4;
    else if (cameraKind == 5)
        rotation *= 1;
}
void Init()
{
    cin >> n >> m;
    MAP.resize(n, vector<int>(m)); //6은 벽, 0은 빈칸, 1~5 카메라
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            if (0 < MAP[i][j] && MAP[i][j] < 6)
            {
                camera.push_back({{MAP[i][j], 0}, {i, j}});
                // multiplyRotation(MAP[i][j]);
            }
        }
    }
}
void spread(int spY, int spX, int rotation)
{
    if (rotation == 0)
    {
        int cnt = 0;
        while (1)
        {
            ++cnt;
            if (spY - cnt < 0 || C_MAP[spY - cnt][spX] == 6)
                break;
            if (C_MAP[spY - cnt][spX] == 0)
                C_MAP[spY - cnt][spX] = -1; //감시표시
        }                                   //위쪽
    }
    else if (rotation == 1)
    {
        int cnt = 0;
        while (1)
        {
            ++cnt;
            if (spX - cnt < 0 || C_MAP[spY][spX - cnt] == 6)
                break;
            if (C_MAP[spY][spX - cnt] == 0)
                C_MAP[spY][spX - cnt] = -1;
        } //왼쪽
    }
    else if (rotation == 2)
    {
        int cnt = 0;
        while (1)
        {
            ++cnt;
            if (spY + cnt >= n || C_MAP[spY + cnt][spX] == 6)
                break;
            if (C_MAP[spY + cnt][spX] == 0)
                C_MAP[spY + cnt][spX] = -1;
        } //아래쪽
    }
    else
    {
        int cnt = 0;
        while (1)
        {
            ++cnt;
            if (spX + cnt >= m || C_MAP[spY][spX + cnt] == 6)
                break;
            if (C_MAP[spY][spX + cnt] == 0)
                C_MAP[spY][spX + cnt] = -1;
        } //오른쪽
    }
}
int getDeadZone()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (C_MAP[i][j] == 0)
                cnt++;

    return cnt;
}
void observation()
{
    C_MAP = MAP;
    for (int i = 0; i < camera.size(); i++)
    {
        int cameraKind = camera[i].first.first;
        int rotation = camera[i].first.second;
        int spY = camera[i].second.first;
        int spX = camera[i].second.second;
        if (cameraKind == 1)
        {
            spread(spY, spX, rotation);
        }
        else if (cameraKind == 2)
        {
            if (rotation == 0 || rotation == 2)
            {
                spread(spY, spX, 1); //왼쪽
                spread(spY, spX, 3); //오른쪽
            }
            else if (rotation == 1 || rotation == 3)
            {
                spread(spY, spX, 0); //위쪽
                spread(spY, spX, 2); //아래쪽
            }
        }
        else if (cameraKind == 3)
        {
            if (rotation == 0)
            {
                spread(spY, spX, 0);
                spread(spY, spX, 3);
            }
            else if (rotation == 1)
            {
                spread(spY, spX, 0); //위쪽
                spread(spY, spX, 1); //왼쪽
            }
            else if (rotation == 2)
            {
                spread(spY, spX, 1); //왼쪽
                spread(spY, spX, 2); //아래쪽
            }
            else
            {
                spread(spY, spX, 2); //아래쪽
                spread(spY, spX, 3); //오른쪽
            }
        }
        else if (cameraKind == 4)
        {
            if (rotation == 0)
            {
                spread(spY, spX, 0); //위쪽
                spread(spY, spX, 1); //왼쪽
                spread(spY, spX, 3); //오른쪽
            }
            else if (rotation == 1)
            {
                spread(spY, spX, 0); //위쪽
                spread(spY, spX, 1); //왼쪽
                spread(spY, spX, 2); //아래쪽
            }
            else if (rotation == 2)
            {
                spread(spY, spX, 1); //왼쪽
                spread(spY, spX, 2); //아래쪽
                spread(spY, spX, 3); //오른쪽
            }
            else
            {
                spread(spY, spX, 2); //아래쪽
                spread(spY, spX, 3); //오른쪽
                spread(spY, spX, 0); //위쪽
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
                spread(spY, spX, i);
        }
    }
}
void Recursion(int k)
{
    if (k == camera.size())
    {
        observation();
        ret = min(ret, getDeadZone());
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        camera[k].first.second = i;
        Recursion(k + 1);
    }
}
void Solve()
{
    Recursion(0);
    cout << ret << endl;
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