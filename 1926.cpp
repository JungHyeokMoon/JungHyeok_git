// #include <bits/stdc++.h>
// using namespace std;

// const int MAX=500;
// int arr[MAX][MAX];
// bool visited[MAX][MAX];
// int n,m;

// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};

// int cnt=0;
// int ret=0;

// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 && x<m){
//         return true;
//     }
//     return false;
// }

// void bfs(int hy, int hx){
//     queue<pair<int,int>> y_x;

//     y_x.push({hy,hx});
//     int hd=0;
//     visited[hy][hx]=true; //방문했다.
//     while(!y_x.empty()){
//         int hy=y_x.front().first;
//         int hx=y_x.front().second;
//         hd++;
//         y_x.pop();

//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(isinside(ny,nx)&&arr[ny][nx]==1&&visited[ny][nx]==false){ //내부에있고 , arr이 1이고 방문하지않았으면
//                 y_x.push({ny,nx});
//                 visited[ny][nx]=true;

//             }
//         }
//     }
//     ret=max(ret,hd);
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>n>>m;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>arr[i][j];
//         }
//     }

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(arr[i][j]==1&&!visited[i][j]){//1이고 방문하지않은곳을 bfs로돈다
//                 bfs(i,j);
//                 cnt++;
//             }
//         }
//     }

//     cout<<cnt<<"\n";
//     cout<<ret<<"\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<vector<int>> MAP;
vector<vector<bool>> visited;
int Count = 0;
int maxSize = -1e9;
const pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isinside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < m)
        return true;
    return false;
}
void Init()
{
    cin >> n >> m;
    MAP.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    int tempSize = 0;
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        tempSize++;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!isinside(ny, nx))
                continue;
            if (visited[ny][nx] == true)
                continue;
            if (MAP[ny][nx] == 1)
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
    maxSize = max(maxSize, tempSize);
}
void Solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (MAP[i][j] == 1 && visited[i][j] == false)
            {
                bfs(i, j);
                Count++;
            }
        }
    }
    cout << Count << endl;
    //  << maxSize << endl;
    if (maxSize == -1e9)
        cout
            << 0 << endl;
    else
    {
        cout << maxSize << endl;
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