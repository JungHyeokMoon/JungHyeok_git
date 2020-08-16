// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// typedef struct Shark{
//     int y, x;
//     int size;
//     int levelupcount;
//     int Time;
// }Shark;
// Shark shark;
// int n;
// typedef struct Feed{
//     int y, x;
//     int Dist;
// }Feed;
// vector<Feed> feedArr;
// vector<vector<int>> arr;
// vector<vector<bool>> visited;
// void Input(){
//     cin>>n;
//     if(n<2 || n>20){
//         exit(1);
//     }// 매개변수가 잘못들어왔을경우 처리해준다.
//     arr.resize(n,vector<int>(n));
//     visited.resize(n,vector<bool>(n,false));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cin>>arr[i][j];
//             if(arr[i][j]==9){
//                 shark.y=i;
//                 shark.x=j;
//                 shark.size=2;
//                 shark.levelupcount=0;
//                 shark.Time=0;
//             } //shark 초기화
//         }
//     }
// }
// const int dy[4]={-1,0,1,0};
// const int dx[4]={0,-1,0,1};
// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 && x<n){
//         return true;
//     }
//     return false;
// }
// bool compare(Feed & A, Feed & B){
//     if(A.Dist<B.Dist){
//         return true;
//     }
//     else if(A.Dist==B.Dist){
//         if(A.y<B.y){
//             return true;
//         }
//         else if(A.y==B.y){
//             if(A.x<B.x){
//                 return true;
//             }
//             return false;
//         }
//         else {
//             return false;
//         }
//     }
//     else{
//         return false;
//     }

// }
// //아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고,
// //나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
// // 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
// void BFS(int y, int x){

//     visited[y][x]=true;
//     queue<pair<pair<int,int>,int>> q; //y ,x 현재까지 움직인거리
//     q.push({{y,x},0});
//     while(!q.empty()){
//         int hy=q.front().first.first;
//         int hx=q.front().first.second;
//         int hd=q.front().second;
//         // cout<<"hy : "<<hy<<" hx : "<<hx<<" hd : "<<hd<<endl;
//         q.pop();

//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             int nd=hd+1;
//             if(!isinside(ny,nx))continue;
//             if(visited[ny][nx])continue;
//             if(arr[ny][nx]==0){
//                 visited[ny][nx]=true;
//                 q.push({{ny,nx},nd});
//             }
//             else if(arr[ny][nx]>shark.size){
//                 continue;
//             }
//             else if(arr[ny][nx]==shark.size){
//                 visited[ny][nx]=true;
//                 q.push({{ny,nx},nd});
//             }
//             else if(arr[ny][nx]<shark.size){
//                 Feed temp;
//                 temp.y=ny;
//                 temp.x=nx;
//                 temp.Dist=nd;

//                 feedArr.push_back(temp);
//                 visited[ny][nx]=true;
//                 q.push({{ny,nx},nd});
//             }
//         }
//     }
//     // sort(feedArr.begin(),feedArr.end(),compare);
//     // for(int i=0; i<feedArr.size(); i++){
//     //     cout<<feedArr[i].y<<" "<<feedArr[i].x<<" "<<feedArr[i].Dist<<endl;
//     // }
//     // cout<<endl;
// }

// void Solve(){
//     while(1){
//         feedArr.clear();
//         for(int i=0; i<n ; i++){
//             fill(visited[i].begin(),visited[i].end(),false);
//         }
//         // cout<<"shark's y : "<<shark.y<<" shark's x : "<<shark.x<<endl;
//         BFS(shark.y,shark.x);
//         if(feedArr.size()==0){
//             cout<<shark.Time<<endl;
//             break;
//         }//없으면끝내고
//         else if(feedArr.size()==1){
//             arr[feedArr[0].y][feedArr[0].x]=9;
//             arr[shark.y][shark.x]=0;
//             shark.y=feedArr[0].y;
//             shark.x=feedArr[0].x;

//             shark.Time+=feedArr[0].Dist;
//             shark.levelupcount++;
//             if(shark.levelupcount==shark.size){
//                 shark.size++;
//                 shark.levelupcount=0;
//             }
//         }//
//         else{
//             sort(feedArr.begin(),feedArr.end(),compare);
//             // for(int i=0; i<feedArr.size(); i++){
//             //     cout<<feedArr[i].y<<" "<<feedArr[i].x<<" "<<feedArr[i].Dist<<endl;
//             // }
//             arr[feedArr[0].y][feedArr[0].x]=9;
//             arr[shark.y][shark.x]=0;
//             shark.y=feedArr[0].y;
//             shark.x=feedArr[0].x;

//             shark.Time+=feedArr[0].Dist;
//             shark.levelupcount++;
//             if(shark.levelupcount==shark.size){
//                 shark.size++;
//                 shark.levelupcount=0;
//             }
//         }
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
int n;
vector<vector<int>> MAP;
int Time = 0;
typedef struct Shark
{
    int y, x; //현재위치
    int size; //사이즈
    int feed; //사이즈 업을 하기위한 먹은 먹이의 수
} Shark;
Shark shark;
pair<int, int> dir[4] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
bool isInside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < n)
        return true;
    return false;
}
void Init()
{
    cin >> n;
    MAP.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 9)
            {
                shark.y = i;
                shark.x = j;
                shark.size = 2;
                shark.feed = 0;
            }
        }
    }
    // cout << shark.y << "," << shark.x << " shark's size" << shark.size << ", shark's feed" << shark.feed << endl;
}
bool bfs(int startY, int startX)
{
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({startY, startX});
    dist[startY][startX] = 0;
    // vector<pair<int,pair<int,int>>> coordi;
    vector<tuple<int,int,int>> coordi;
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        if (MAP[hy][hx] < shark.size && MAP[hy][hx] != 9 && MAP[hy][hx] != 0)
            // coordi.push_back({hy,hx});
            // coordi.push_back({dist[hy][hx],{hy, hx}});
            coordi.push_back(make_tuple(dist[hy][hx],hy,hx));
        
        for (int i = 0; i < 4; i++)
        {
            int ny = hy + dir[i].first;
            int nx = hx + dir[i].second;
            if (!isInside(ny, nx))
                continue; //맵범위 넘어가면 x
            if (dist[ny][nx] != -1)
                continue; //이미 방문했다면 x
            if (MAP[ny][nx] > shark.size)
                continue; //못건너감
            q.push({ny, nx});
            dist[ny][nx] = dist[hy][hx] + 1;
        }
    }
    if (!coordi.empty())
    {
        sort(coordi.begin(),coordi.end());
        MAP[startY][startX] = 0;
        // int hy = coordi[0].second.first;
        // int hx = coordi[0].second.second;
        // Time += dist[hy][hx];
        int hP,hy,hx;
        tie(hP,hy,hx)=coordi[0];
        Time+=hP;
        shark.feed++;
        if (shark.feed == shark.size)
        {
            shark.feed = 0;
            shark.size++;
        }
        shark.y = hy;
        shark.x = hx;
        MAP[hy][hx] = 9;
        // cout << "Time: " << Time << endl;
        // cout << shark.y << "," << shark.x << " shark's size" << shark.size << ", shark's feed" << shark.feed << endl;

        // cout << "----------MAP OUTPUT--------------" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << MAP[i][j] << " ";
        //         if(j==5) cout<<" || ";
        //     }
        //     for(int j=0; j<n; j++)
        //         cout<<dist[i][j]<<" ";
        //     cout << endl;
        // }
        // cout << "-----------------------------------" << endl;
        return true;
    }

    return false;
}
void Solve()
{
    while (bfs(shark.y, shark.x))
    {
    }
    cout << Time << endl;
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