// #include <bits/stdc++.h>
// using namespace std;

// int r,c;
// char swan[1500][1500];

// int dy[4]={1,0,-1,0};
// int dx[4]={0,1,0,-1};
// bool isvisited[1500][1500];
// int ret=0;
// bool flag=false;
// bool isinside(int y, int x){
//     if(y>=0 && y<r && x>=0 && x<c){
//         return true;
//     }
//     return false;
// }

// queue<pair<int,int>> water_q,water_nq,swan_q,swan_nq;
// typedef struct pos{
//     int y,x;
// }pos;
// pos swancoordi[2];
// bool swan_bfs(){

//     while(!swan_q.empty()){
//         int hy=swan_q.front().first;
//         int hx=swan_q.front().second;
//         swan_q.pop();
//         if(hy==swancoordi[1].y && hx==swancoordi[1].x){
//             return true;
//         }
//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;
//             if(isvisited[ny][nx])continue;
//             if(swan[ny][nx]=='.' || swan[ny][nx]=='L'){
//                 isvisited[ny][nx]=true;
//                 swan_q.push(make_pair(ny,nx));
//             }
//             else{
//                 isvisited[ny][nx]=true;
//                 swan_nq.push(make_pair(ny,nx));
//             }

//         }
//     }

//     return false;
// }
// void water_bfs(){
//     while(!water_q.empty()){
//         int hy=water_q.front().first;
//         int hx=water_q.front().second;
//         water_q.pop();
//         for(int i=0; i<4 ; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;
//             if(swan[ny][nx]=='X'){
//                 swan[ny][nx]='.';
//                 water_nq.push(make_pair(ny,nx));
//             }
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin>>r>>c;
//     int k=0;
//     for(int i=0; i<r; i++){
//         string temp;
//         cin>>temp;
//         for(int j=0; j<c; j++){
//             swan[i][j]=temp[j];
//             if(swan[i][j]!='X')water_q.push(make_pair(i,j));
//             if(swan[i][j]=='L'){
//                 swancoordi[k++]={i,j};
//             }
//         }
//     }

//     swan_q.push(make_pair(swancoordi[0].y,swancoordi[0].x));
//     isvisited[swancoordi[0].y][swancoordi[0].x]=true;
//     while(1){

//         flag=swan_bfs();
//         if(flag){
//             cout<<ret<<"\n";
//             break;
//         }
//         water_bfs();
//         water_q=water_nq;
//         swan_q=swan_nq;

//         while(!water_nq.empty())water_nq.pop();
//         while(!swan_nq.empty())swan_nq.pop();
//         ret++;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int r, c;
vector<vector<char>> MAP;
vector<vector<bool>> swan_visited;
vector<vector<bool>> water_visited;
queue<pair<int, int>> swan_q, water_q;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isInside(int y, int x)
{
    if (y >= 0 && y < r && x >= 0 && x < c)
        return true;
    return false;
}
void Init()
{
    cin >> r >> c;
    MAP.resize(r, vector<char>(c));
    water_visited.resize(r, vector<bool>(c, false));
    swan_visited.resize(r, vector<bool>(c, false));
    bool first_swan = true;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'L')
            {
                if (first_swan)
                {
                    swan_visited[i][j] = true;
                    swan_q.push({i, j});
                    first_swan = false;
                }
                water_q.push({i, j});
                water_visited[i][j] = true;
            }
            else if (MAP[i][j] == '.')
            {
                water_q.push({i, j});
                water_visited[i][j] = true;
            }
        }
    }
}
void Output()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool swan_bfs()
{
    vector<pair<int, int>> temp;
    while (!swan_q.empty())
    {
        auto cur = swan_q.front();
        swan_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dir[i].first;
            int nx = cur.second + dir[i].second;

            if (!isInside(ny, nx))
                continue;
            if (swan_visited[ny][nx])
                continue;
            if (MAP[ny][nx] == 'L')
                return true;
            if (MAP[ny][nx] == 'X')
            {
                temp.push_back({ny, nx});
                swan_visited[ny][nx] = true;
            }
            else if (MAP[ny][nx] == '.')
            {
                swan_visited[ny][nx] = true;
                swan_q.push({ny, nx});
            }
        }
    }
    for (pair<int, int> p : temp)
    {
        swan_q.push(p);
    }
    return false;
}
void water_bfs()
{
    vector<pair<int, int>> temp;
    while (!water_q.empty())
    {
        auto cur = water_q.front();
        water_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dir[i].first;
            int nx = cur.second + dir[i].second;

            if (!isInside(ny, nx))
                continue;
            if (water_visited[ny][nx])
                continue;
            if (MAP[ny][nx] == 'X')
            {
                MAP[ny][nx] = '.';
                water_visited[ny][nx] = true;
                temp.push_back({ny, nx});
            }
            else if (MAP[ny][nx] == '.')
            {
                water_q.push({ny, nx});
                water_visited[ny][nx] = true;
            }
        }
    }
    for (pair<int, int> p : temp)
    {
        water_q.push(p);
    }
}
void Solve()
{
    int Day = 0;
    while (1)
    {
        if (swan_bfs())
        {
            cout << Day << endl;
            return;
        }
        Day++;
        water_bfs();
    }
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