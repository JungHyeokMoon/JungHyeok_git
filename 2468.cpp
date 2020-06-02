// #include <bits/stdc++.h>
// using namespace std;

// int n;
// const int MAX=100;
// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 && x<n){
//         return true;
//     }
//     return false;
// }
// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// int arr[MAX][MAX];

// int max_range=-987654321;
// bool visited[MAX][MAX];
// int ret=-987654321;

// void init(){
//     for(int i=0; i<n; i++){
//         fill(visited[i],visited[i]+n,false);
//     }
// }

// void bfs(int y, int x,int range){
//    // cout<<"bfs here"<<"\n";
//     queue<pair<int,int >>q;
//     q.push({y,x});
//     visited[y][x]=true;

//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;

//         q.pop();
//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(isinside(ny,nx)&&!visited[ny][nx]&&arr[ny][nx]>range){
//                 visited[ny][nx]=true;
//                 q.push({ny,nx});
//             }
//         }
//     }
// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>n;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cin>>arr[i][j];
//             max_range=max(max_range,arr[i][j]);
//         }
//     }
//     //cout<<"max_range : "<<max_range<<"\n";
//     for(int k=0; k<=max_range; k++){
//         init();
//         int temp=0;
//         //cout<<"k : "<<k<<"\n";
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 //cout<<"i : "<<i<<" , "<<"j : "<<j<<"\n";
//                 if(!visited[i][j] && arr[i][j]>k){// N 이하인 애들이 잠긴다. 그래서 초과인애들 bfs돌려서 몇개인지 찾아야함
//                     temp++;
//                     bfs(i,j,k);
//                     //cout<<"k : "<<k<<" , "<<"temp : "<<temp<<"\n";
//                 }
//             }
//         }
//         ret=max(ret,temp);
//     }

//     cout<<ret<<"\n";
//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> MAP;
vector<vector<bool>> visited;
// int minHeight = 1e9;
int maxHeight = -1e9;
int ret = -1e9;
bool isinside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < n)
        return true;
    return false;
}
void Init()
{
    cin >> n;
    MAP.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            // minHeight = min(minHeight, MAP[i][j]);
            maxHeight = max(maxHeight, MAP[i][j]);
        }
    }
    // cout << minHeight << " " << maxHeight << endl;
}
void bfs(int y, int x, int h)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    while (!q.empty())
    {
        auto cur = q.front();
        int hy = cur.first;
        int hx = cur.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!isinside(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            if (MAP[ny][nx] > h)
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
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
    for (int i = 0; i <= maxHeight; i++)
    {
        resetVisited();
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (MAP[j][k] > i && visited[j][k] == false)
                {
                    temp++;
                    bfs(j, k, i);
                }
            }
        }
        ret = max(ret, temp);
    }
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