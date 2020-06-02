// #include <bits/stdc++.h>
// using namespace std;
// int n,m;
// const int MAX=300;
// int iceberg[MAX][MAX];
// int C_iceberg[MAX][MAX];
// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 && x<m){
//         return true;
//     }
//     return false;
// }
// bool visited[MAX][MAX];
// int year;
// void copyMap(){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m ; j++){
//             iceberg[i][j]=C_iceberg[i][j];
//         }
//     }
// }

// int Melt(int y, int x){
//     int cnt=0;
//     for(int i=0; i<4 ; i++){
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         if(isinside(ny,nx)&&!iceberg[ny][nx])cnt++;
//     }
//     return cnt;
// }

// void bfs(int y,int x){
//     queue<pair<int,int>>q;
//     visited[y][x]=true;
//     q.push({y,x});

//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;
//         q.pop();
//         //cout<<"year : "<<year<<" , "<<"hy : "<<hy<<" , "<<"hx : "<<hx<<"\n";
//         for(int i=0 ; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];

//             if(isinside(ny,nx) && !visited[ny][nx] && iceberg[ny][nx]){
//                 visited[ny][nx]=true;
//                 q.push({ny,nx});
//             }
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n>>m;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>iceberg[i][j];
//         }
//     }

//     while(1){
//         int LandCount=0;
//         memset(visited,false,sizeof(visited));
//         memset(C_iceberg,0,sizeof(C_iceberg));

//         for(int i=0 ; i< n ; i++){
//             for(int j=0; j< m; j++){
//                 if(!visited[i][j]&&iceberg[i][j]){
//                    //cout<<"i : "<<i<<", j : "<<j<<"\n";
//                     LandCount++;
//                     bfs(i,j);
//                 }
//             }
//         }
//        // cout<<"year : "<<year<<" , "<<"Landcount : "<<LandCount<<"\n";

//         if(LandCount>=2){
//             cout<<year<<"\n";
//             return 0;
//         }
//         else if(!LandCount){
//             cout<<"0"<<"\n";
//             return 0;
//         }

//         for(int i=0 ; i< n ;i++){
//             for(int j=0; j<m; j++){
//                 if(iceberg[i][j]){
//                     C_iceberg[i][j]=iceberg[i][j]-Melt(i,j);
//                     if(C_iceberg[i][j]<0)C_iceberg[i][j]=0;
//                 }
//             }
//         }

//         copyMap();
//         year++;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
vector<vector<int>> iceberg;
vector<vector<bool>> visited;
queue<pair<pair<int, int>, int>> q;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int Time = 0;
bool Isinside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < m)
        return true;
    return false;
}
void Init()
{
    cin >> n >> m;
    iceberg.resize(n, vector<int>(m));
    // cIceberg.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> iceberg[i][j];
            // if (iceberg[i][j] > 0)
            // {
            //     q.push({{i, j}, CountZero(i, j)});
            // }
        }
    }
}
void Output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << iceberg[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int CountZero(int hy, int hx)
{
    int ret = 0;

    for (int i = 0; i < 4; i++)
    {
        int cy = hy + d[i].first;
        int cx = hx + d[i].second;
        // cout << "ny : " << cy << " nx :" << cx << endl;
        if (!Isinside(cy, cx))
            continue;
        else if (iceberg[cy][cx] == 0)
        {
            ret++;
        }
    }
    // cout << "hy : " << hy << " hx : " << hx << " , zero :" << ret << endl;
    return ret;
}
void Melt()
{
    int qsize = q.size();
    for (int i = 0; i < qsize; i++)
    {
        auto cur = q.front();
        int hy = cur.first.first;
        int hx = cur.first.second;
        int zero = cur.second;
        q.pop();
        // cout << "hy : " << hy << " , hx : " << hx << " , zero" << zero << endl;
        // int Compare = iceberg[hy][hx] - zero;
        // if (Compare >= 0)
        // {
        //     iceberg[hy][hx] = Compare;
        // }
        // else
        // {
        //     iceberg[hy][hx] = 0;
        // }
        iceberg[hy][hx] = (iceberg[hy][hx] - zero) < 0 ? 0 : iceberg[hy][hx] - zero;
    }
}
void bfs(int y, int x)
{
    queue<pair<int, int>> bfsq;
    visited[y][x] = true;
    bfsq.push({y, x});
    while (!bfsq.empty())
    {
        int hy = bfsq.front().first;
        int hx = bfsq.front().second;
        q.push({{hy, hx}, CountZero(hy, hx)});
        bfsq.pop();
        // cout << "hy : " << hy << " , hx : " << hx << endl;
        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!Isinside(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            if (iceberg[ny][nx] > 0)
            {
                bfsq.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}
void resetVisited()
{
    for (int i = 0; i < n; i++)
    {
        fill(visited[i].begin(), visited[i].end(), false);
    }
}
void Solve()
{
    while (1)
    {
        int Count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (iceberg[i][j] != 0 && visited[i][j] == false)
                {
                    Count++;
                    bfs(i, j);
                }
            }
        }
        // cout << "Count :" << Count << endl;
        if (Count >= 2)
        {
            cout << Time << endl;
            return;
        }
        else if (Count == 0)
        {
            cout << 0 << endl;
            return;
        }
        // Output();
        // if (Time == 1)
        // {
        //     exit(0);
        // }
        resetVisited();
        Melt();
        Time++;
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