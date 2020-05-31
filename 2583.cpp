// #include <bits/stdc++.h>
// using namespace std;

// int m,n,k;
// const int MAX=100;
// int arr[MAX][MAX];
// bool visited[MAX][MAX];

// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// int cnt=0;
// vector<int > ret;
// bool isinside(int y, int x){
//     if(y>=0 && y<m && x>=0 && x<n){
//         return true;
//     }
//     return false;
// }

// void check_area(int x1,int y1, int x2, int y2){
//     for(int i=y1; i<y2; i++){
//         for(int j=x1; j<x2; j++){
//             arr[i][j]=-1;
//         }
//     }
// }

// void bfs(int y, int x){
//     int area=0;
//     queue<pair<int,int>> q;

//     q.push({y,x});
//     visited[y][x]=true;

//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;
//         area++;
//         q.pop();
//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(isinside(ny,nx)&& arr[ny][nx]==0 && visited[ny][nx]==false){
//                 visited[ny][nx]=true;
//                 q.push({ny,nx});
//             }
//         }
//     }

//     ret.push_back(area);
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>m>>n>>k;
//     for(int i=0; i<k; i++){
//         int x1,y1,x2,y2;
//         cin>>x1>>y1>>x2>>y2;
//         check_area(x1,y1,x2,y2);
//     }

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(arr[i][j]==0&&visited[i][j]==0){
//                 bfs(i,j);
//             }
//         }
//     }

//     //답출력

//     sort(ret.begin(),ret.end());
//     int len=ret.size();
//     cout<<len<<"\n";
//     for(int i=0; i<len; i++){
//         cout<<ret[i]<<" ";
//     }
//     cout<<"\n";

//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int m, n, k;
vector<vector<int>> MAP;
vector<vector<bool>> visited;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<int> ret;
bool isinside(int y, int x)
{
    if (y >= 0 && y < m && x >= 0 && x < n)
        return true;
    return false;
}

void Init()
{
    cin >> m >> n >> k;
    MAP.resize(m, vector<int>(n, false));
    visited.resize(m, vector<bool>(n, false));
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = m - y2; i < m - y1; i++)
        {
            for (int j = x1; j < x2; j++)
            {
                MAP[i][j] = 1;
            }
        }
    }
}
int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push({y, x});
    int temp = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        int hy = cur.first;
        int hx = cur.second;
        q.pop();
        temp++;

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!isinside(ny, nx))
                continue;
            if (MAP[ny][nx] == 1)
                continue;
            if (visited[ny][nx] == true)
                continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    return temp;
}
void Output()
{
    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (auto i : ret)
    {
        cout << i << " ";
    }
}
void Cal()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (MAP[i][j] == 0 && visited[i][j] == false)
            {
                ret.push_back(bfs(i, j));
            }
        }
    }
}
void Solve()
{
    Cal();
    Output();
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