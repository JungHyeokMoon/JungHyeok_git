// #include <bits/stdc++.h>
// using namespace std;
// char YS[5][5];
// bool isvisited[5][5];
// int ret=0;
// int dy[4]={1,0,-1,0};
// int dx[4]={0,1,0,-1};
// bool isinside(int y,int x){
//     if(y>=0 && y<5 && x>=0 &&x<5){
//         return true;
//     }
//     return false;
// }
// bool morethanfour(){
//     int cnt=0;
//     for(int i=0; i<25; i++){
//         int y=i/5;
//         int x=i%5;
//         if(isvisited[y][x] && YS[y][x]=='S'){
//             cnt++;
//             if(cnt>=4){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool Adjacenct(){
//     queue<pair<int,int>>q;
//     bool check1[5][5]; //check용
//     bool check2[5][5]; //큐용
//     memset(check1,false,sizeof(check1));
//     memset(check2,false,sizeof(check2));

//     bool first=false;
//     for(int i=0; i<5*5; i++){
//         int y=i/5;
//         int x=i%5;
//         if(isvisited[y][x]){
//             check1[y][x]=true;
//             if(!first){
//                 first=true;
//                 q.push(make_pair(y,x));
//                 check2[y][x]=true;
//             }
//         }
//     }

//     int cnt=1;
//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;

//         q.pop();
//         if(cnt==7){
//             return true;
//         }

//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];

//             if(!isinside(ny,nx))continue;
//             if(check1[ny][nx]&&!check2[ny][nx]){
//                 cnt++;
//                 q.push(make_pair(ny,nx));
//                 check2[ny][nx]=true;
//             }
//         }
//     }
//     return false;
// }
// void dfs(int idx, int cnt){
//     if(cnt==7){
//         if(morethanfour() && Adjacenct()){
//             ret++;
//         }
//         return ;
//     }

//     for(int i=idx+1; i<5*5; i++){
//         int y=i/5;
//         int x=i%5;

//         if(!isvisited[y][x]){
//             isvisited[y][x]=true;
//             dfs(i,cnt+1); // i를 넘겨줘야함 idx 를 넘겨줘버리면 무한루프발생
//             isvisited[y][x]=false;
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     for(int i=0; i<5; i++){
//         string temp;
//         cin>>temp;
//         for(int j=0; j<5; j++){
//             YS[i][j]=temp[j];
//         }
//     }

//     dfs(-1,0);
//     cout<<ret<<"\n";

//     return 0;
// }
// //처음 7명의 조합을 찾고 7명이됐을때 개냬가 4명이상이 이다솜파인지 그리고 붙어있는지 체크해야함

#include <bits/stdc++.h>
#define endl "\n"
#define MAPSIZE 5
#define Princess 7
#define MinCon 4
using namespace std;
vector<vector<char>> MAP;

pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int ans = 0;
vector<pair<int, int>> ret;

void Init()
{
    MAP.resize(MAPSIZE, vector<char>(MAPSIZE));

    for (int i = 0; i < MAPSIZE; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < MAPSIZE; j++)
        {
            MAP[i][j] = input[j];
        }
    }
}
bool isInside(int y, int x)
{
    if (y >= 0 && y < MAPSIZE && x >= 0 && x < MAPSIZE)
    {
        return true;
    }
    return false;
}
bool Adj()
{
    vector<vector<bool>> visited1(MAPSIZE, vector<bool>(MAPSIZE, false));
    vector<vector<bool>> visited2(MAPSIZE, vector<bool>(MAPSIZE, false));

    for (int i = 0; i < ret.size(); i++)
    {
        int hy = ret[i].first;
        int hx = ret[i].second;
        visited1[hy][hx] = true;
    }
    int cnt = 0;
    queue<pair<int, int>> q;
    visited2[ret[0].first][ret[0].second] = true;
    q.push({ret[0].first, ret[0].second});
    while (!q.empty())
    {
        auto cur = q.front();
        int hy = cur.first;
        int hx = cur.second;
        cnt++;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + dir[i].first;
            int nx = hx + dir[i].second;
            if (!isInside(ny, nx))
                continue;
            if (!visited1[ny][nx])
                continue;
            if (!visited2[ny][nx])
            {
                visited2[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    if (cnt == Princess)
        return true;
    return false;
}
bool moreThanFour()
{
    int s = 0, y = 0;
    for (int i = 0; i < ret.size(); i++)
    {
        int hy = ret[i].first;
        int hx = ret[i].second;
        if (MAP[hy][hx] == 'S')
            s++;
        else
            y++;
    }
    if (s >= MinCon)
        return true;
    return false;
}
void Recursion(int row, int col)
{
    if (row == MAPSIZE)
        return;
    if (ret.size() == Princess)
    {
        if (Adj() && moreThanFour())
            ans++;
        return;
    }

    if (col >= MAPSIZE)
    {
        row++;
        col = 0;
    }
    ret.push_back({row, col});
    Recursion(row, col + 1);
    ret.pop_back();
    Recursion(row, col + 1);
}
void Solve()
{
    Recursion(0, 0);
    cout << ans << endl;
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
