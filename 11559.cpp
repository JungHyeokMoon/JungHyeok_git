// #include <bits/stdc++.h>
// using namespace std;
// char Puyo[12][6];
// int ret=0;
// int dy[4]={-1,0,1,0};
// int dx[4]={0,1,0,-1};
// bool isinside(int y,int x){
//     if(y>=0 && y<12 &&x>=0 &&x<6){
//         return true;
//     }
//     return false;
// }
// bool bfs(int y,int x){
//     bool flag=false;
//     bool isvisited[12][6]={false};
//     isvisited[y][x]=true;
//     queue<pair<int,int>> q;
//     vector<pair<int,int>> v;
//     char temp=Puyo[y][x];
//     q.push({y,x});
//     v.push_back({y,x});
//     int cnt=0;
//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;
//         cnt++;
//         q.pop();

//         for(int i=0; i<4 ; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;
//             if(isvisited[ny][nx])continue;
//             if(Puyo[ny][nx]==temp){
//                 q.push({ny,nx});
//                 isvisited[ny][nx]=true;
//                 v.push_back({ny,nx});

//             }
//         }
//     }
//     if(cnt>=4){
//         flag=true;
//         for(int i=0; i<v.size(); i++){
//             Puyo[v[i].first][v[i].second]='.';
//         }
//     }
//     return flag;
// }

// void Input(){
//     for(int i=0; i<12 ; i++){
//         for(int j=0; j<6; j++){
//             cin>>Puyo[i][j];
//         }
//     }
// }
// void Output(){
//     cout<<"\\\\\\\\"<<"\n";
//     for(int i=0; i<12; i++){
//         for(int j=0; j<6; j++){
//             cout<<Puyo[i][j];
//         }
//         cout<<"\n";
//     }
// }
// bool Crash(){
//     bool flag=false;
//     for(int i=11; i>=0 ;i--){
//         for(int j=5; j>=0; j--){
//             if(Puyo[i][j]=='.')continue;
//             if(bfs(i,j))flag=true;
//         }
//     }
//     return flag;
// }
// void fall(){
//     for(int j=0; j<6; j++){
//         for(int i=11; i>=0; i--){
//             if(Puyo[i][j]=='.')continue;
//             for(int k=11; k>=i; k--){
//                 if(Puyo[k][j]=='.'){
//                     Puyo[k][j]=Puyo[i][j];
//                     Puyo[i][j]='.';
//                 }
//             }
//         }
//     }
// }
// void Solve(){
//     int ans=0;
//     while(Crash()){
//         //Output();
//         fall();
//         ans++;
//     }
//     cout<<ans<<"\n";
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
#define row 12
#define col 6
using namespace std;
vector<vector<char>> MAP;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int ret = 0;
bool isInside(int y, int x)
{
    if (y >= 0 && y < row && x >= 0 && x < col)
        return true;
    return false;
}

void Init()
{
    MAP.resize(row, vector<char>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

void bfs(int y, int x)
{
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    char P = MAP[y][x];
    MAP[y][x] = '.';
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + dir[i].first;
            int nx = hx + dir[i].second;

            if (!isInside(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            if (MAP[ny][nx] == P)
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
                MAP[ny][nx] = '.';
            }
        }
    }
}
bool Burstable(int y, int x)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visitied(row, vector<bool>(col, false));
    int cnt = 0;
    q.push({y, x});
    visitied[y][x] = true;
    char P = MAP[y][x];
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        cnt++;
        if (cnt >= 4)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + dir[i].first;
            int nx = hx + dir[i].second;
            if (!isInside(ny, nx))
                continue;
            if (visitied[ny][nx])
                continue;
            if (MAP[ny][nx] == P)
            {
                q.push({ny, nx});
                visitied[ny][nx] = true;
            }
        }
    }
    return false;
}
void PuyoDown()
{
    for (int i = 0; i < col; i++)
    {
        queue<int> q;
        for (int j = row - 1; j >= 0; j--)
        {
            if (MAP[j][i] != '.')
            {
                q.push(MAP[j][i]);
                MAP[j][i] = '.';
            }
        }

        int idx = row - 1;
        while (!q.empty())
        {
            char c = q.front();
            q.pop();

            if (MAP[idx][i] == '.')
                MAP[idx][i] = c;
            else
                MAP[--idx][i] = c;
        }
    }
}
void Output()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Solve()
{

    while (1)
    {
        bool flag = false;
        for (int i = 0; i < col; i++)
        {
            for (int j = row - 1; j >= 0; j--)
            {
                if (MAP[j][i] != '.')
                {
                    if (Burstable(j, i))
                    {
                        if (!flag)
                            ret++;
                        flag = true;
                        bfs(j, i);
                    }
                }
            }
        }
        // Output();
        PuyoDown();
        if (flag == false)
            break;
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