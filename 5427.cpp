// #include <bits/stdc++.h>
// using namespace std;
// int t;
// int w,h;
// const int MAX=1000;
// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// bool isinside(int y, int x){
//     if(y>=0 && y<h && x>=0 && x<w){
//         return true;
//     }
//     return false;
// }
// char Fire[MAX][MAX];
// typedef struct pos{
//     int y,x,sec;
//     bool type;
// }pos;
// pos sp;
// queue<pos>q;
// void input(){
//     cin>>w>>h;
//     for(int i=0; i<h; i++){
//         for(int j=0; j<w; j++){
//             cin>>Fire[i][j];
//             if(Fire[i][j]=='@'){
//                 sp.y=i;
//                 sp.x=j;
//             }
//             else if(Fire[i][j]=='*'){
//                 q.push({i,j,0,false});
//             }
//         }
//     }
// }
// bool visited[MAX][MAX];
// void emptyforq(){
//     while(!q.empty())q.pop();
// }

// int bfs(){
//     visited[sp.y][sp.x]=true;
//     q.push({sp.y,sp.x,0,true}); //불먼저 태워야함
//     while(!q.empty()){
//         int hy=q.front().y;
//         int hx=q.front().x;
//         int pop_sec=q.front().sec;
//         int pop_type=q.front().type;
//         q.pop();

//         if(pop_type && (hy==0 || hy==h-1||hx==0||hx==w-1))return pop_sec+1;

//         for(int i=0 ; i<4; i++){
//             int ny =hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;
//             if(Fire[ny][nx]=='#'||Fire[ny][nx]=='*')continue;
//             if(visited[ny][nx])continue;

//             if(pop_type)visited[ny][nx]=true;
//             else Fire[ny][nx]='*';

//             q.push({ny,nx,pop_sec+1,pop_type});

//         }
//     }

//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>t;
//     for(int i=0; i<t; i++){
//         emptyforq();
//         input();
//         memset(visited,false,sizeof(visited));

//         int ret=bfs();
//         if(ret)cout<<ret<<"\n";
//         else cout<<"IMPOSSIBLE"<<"\n";
//     }

//     return 0;
// }
// //참고해서풀었습니다.https://donggod.tistory.com/18

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int t;
int w, h;
vector<vector<char>> MAP;
vector<vector<int>> Dist;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> v;
pair<int, int> S;
bool Isinside(int y, int x)
{
    if (y >= 0 && y < h && x >= 0 && x < w)
        return true;
    return false;
}
void Init()
{
    cin >> w >> h;
    MAP.clear();
    MAP.resize(h, vector<char>(w));
    Dist.clear();
    Dist.resize(h, vector<int>(w, -1));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == '@')
            {
                //상근이의위치
                S = {i, j};
                // cout << "y : " << i << " x: " << j << endl;
            }
            else if (MAP[i][j] == '*')
            {
                //불의위치
                v.push_back({i, j});
            }
        }
    }
}
void Output()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int Cal(int t)
{
    queue<pair<int, int>> fire;
    queue<pair<int, int>> Sanguen;
    Sanguen.push({S.first, S.second});
    Dist[S.first][S.second] = 0;
    // cout << Sanguen.front().first << " " << Sanguen.front().second << endl;
    for (auto i : v)
    {
        fire.push(i);
        // cout << "fire : " << i.first << " " << i.second << endl;
    }
    // cout << endl;

    while (1)
    {
        int fireS = fire.size();
        for (int i = 0; i < fireS; i++)
        {
            auto cur = fire.front();
            int hy = cur.first;
            int hx = cur.second;
            fire.pop();

            for (int j = 0; j < 4; j++)
            {
                int ny = hy + d[j].first;
                int nx = hx + d[j].second;
                if (!Isinside(ny, nx))
                    continue;
                if (MAP[ny][nx] == '#' || MAP[ny][nx] == '*')
                    continue;
                fire.push({ny, nx});
                MAP[ny][nx] = '*';
            }
        }
        // if (t == 3)
        // {
        // Output();
        // }
        int SanguenSize = Sanguen.size();
        for (int i = 0; i < SanguenSize; i++)
        {
            auto cur = Sanguen.front();
            int hy = cur.first;
            int hx = cur.second;
            // if (t == 3)
            // {
            // cout << "hy : " << hy << " hx : " << hx << " Dist[hy][hx] : " << Dist[hy][hx] << endl;
            // }
            Sanguen.pop();
            if (hy == 0 || hy == h - 1 || hx == 0 || hx == w - 1)
            {
                return Dist[hy][hx] + 1;
            }

            for (int j = 0; j < 4; j++)
            {
                int ny = hy + d[j].first;
                int nx = hx + d[j].second;
                if (!Isinside(ny, nx))
                    continue;
                if (MAP[ny][nx] == '#' || MAP[ny][nx] == '*')
                    continue;
                if (Dist[ny][nx] >= 0)
                    continue;
                Sanguen.push({ny, nx});
                Dist[ny][nx] = Dist[hy][hx] + 1;
                // cout << "ny : " << ny << " nx : " << nx << " , Dist[ny][nx]" << Dist[ny][nx] << endl;
            }
        }

        if (Sanguen.size() == 0)
        {
            return -1;
        }
    }
}
void Solve()
{
    cin >> t;
    while (t--)
    {
        Init();
        int ret = Cal(t);
        if (ret == -1)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << ret << endl;
        }
        v.clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}