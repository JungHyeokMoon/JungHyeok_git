// #include <bits/stdc++.h>
// using namespace std;
// int n,k,l;
// int apple[100][100];
// queue<pair<int,char>> direction;
// //뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
// queue<pair<int,int>> snake;
// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// int L[4]={1,2,3,0};
// int D[4]={3,0,1,2};
// int ret=0;
// void Input(){
//     cin>>n;
//     cin>>k;
//     for(int i=0; i<k; i++){
//         int y,x;
//         cin>>y>>x;
//         apple[y-1][x-1]=1; //사과의 위치는 1
//     }
//     cin>>l;
//     for(int i=0; i<l; i++){
//         int second;
//         char direc;
//         cin>>second>>direc;
//         direction.push({second,direc}); //l왼쪽 , d오른쪽
//     }
// }
// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 && x<n)
//         return true;
//     return false;
// }
// void Solve(){
//     //뱀의 시작위치는 0,0
//     apple[0][0]=2;
//     snake.push({0,0});
//     int hx=0,hy=0;
//     int d=0;
//     while(1){
//         hy+=dy[d];
//         hx+=dx[d];
//         ret++;
//         if(!isinside(hy,hx)||apple[hy][hx]==2){
//             cout<<ret<<"\n";
//             return ;
//         }
//         if(apple[hy][hx]==0){
//             int tale_y=snake.front().first;
//             int tale_x=snake.front().second;
//             snake.pop();
//             apple[tale_y][tale_x]=0;
//         }
//         apple[hy][hx]=2;
//         snake.push({hy,hx});
//         if(ret==direction.front().first){
//             if(direction.front().second=='L'){
//                 d=L[d];
//             }
//             else if(direction.front().second=='D'){
//                 d=D[d];
//             }
//             direction.pop();
//         }
//     }

// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     Input();
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k, l;
vector<pair<int, char>> cmd;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //위 오른쪽 아래 왼쪽
int d = 1;
int hy = 0, hx = 0;
int Time = 0;
vector<vector<int>> MAP;
bool isInside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < n)
        return true;
    return false;
}
void Init()
{
    cin >> n >> k;
    MAP.resize(n, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a - 1][b - 1] = 1;
    }
    cin >> l;
    cmd.resize(l);
    for (int i = 0; i < l; i++)
        cin >> cmd[i].first >> cmd[i].second;
    MAP[0][0] = 2;
}
void Output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Solve()
{
    deque<pair<int, int>> dq;
    dq.push_front({hy, hx});
    int idx = 0;
    while (1)
    {
        if (cmd[idx].first == Time)
        {
            d = cmd[idx].second == 'L' ? (d + 3) % 4 : (d + 1) % 4;
            idx++;
        }
        int ny = hy + dir[d].first;
        int nx = hx + dir[d].second;

        if (!isInside(ny, nx) || MAP[ny][nx] == 2)
            break;
        dq.push_front({ny, nx});
        if (MAP[ny][nx] == 1)
        {
            // cout << "ny : " << ny << " nx : " << nx << endl;
            MAP[ny][nx] = 2;
        }
        else if (MAP[ny][nx] == 0)
        {
            MAP[ny][nx] = 2;
            int ty = dq.back().first;
            int tx = dq.back().second;
            MAP[ty][tx] = 0;
            dq.pop_back();
        }

        hy = ny;
        hx = nx;
        Time++;
        // Output();
    }
    cout << Time + 1 << endl;
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