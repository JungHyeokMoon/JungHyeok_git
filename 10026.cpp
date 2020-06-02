// #include <bits/stdc++.h>
// using namespace std;

// int n;
// const int MAX=100;
// char MAP[MAX][MAX];
// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// bool visited[MAX][MAX];
// int ret1=0;
// int ret2=0;
// bool isinside(int y, int x){
//     if(y>=0 && y<n && x>=0 && x<n){
//         return true;
//     }
//     return false;
// }

// void input(){
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<n ; j++){
//             cin>>MAP[i][j];
//         }
//     }
// }

// void output(){
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<n ; j++){
//             cout<<MAP[i][j];
//         }
//         cout<<"\n";
//     }
// }

// void init(){
//     for(int i=0; i<n ; i++){
//         fill(visited[i],visited[i]+n,false);
//     }
// }

// void bfs(int y, int x,bool flag){ // flag가 false 인경우 는 적록색약이 아닌경우
//     char temp=MAP[y][x];
//     queue<pair<int,int>> q;

//     q.push({y,x});
//     visited[y][x]=true;

//     while(!q.empty()){
//         int hy=q.front().first;
//         int hx=q.front().second;

//         q.pop();
//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;
//             if(visited[ny][nx])continue;
//             if(flag){
//                 if(MAP[ny][nx]==temp){
//                     visited[ny][nx]=true;
//                     q.push({ny,nx});
//                 }
//             }//적록색약이아닌경우
//             else{
//                 if(temp=='B'){
//                     if(MAP[ny][nx]=='B'){
//                         visited[ny][nx]=true;
//                         q.push({ny,nx});
//                     }
//                 }
//                 else{
//                     if(MAP[ny][nx]=='G'||MAP[ny][nx]=='R'){
//                         visited[ny][nx]=true;
//                         q.push({ny,nx});
//                     }
//                 }
//             }//적록색약인경우
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n;

//     input();
//     init();

//     for(int i=0; i<n ; i++){
//         for(int j=0; j<n ; j++){
//             if(!visited[i][j]){
//                 bfs(i,j,true);
//                 ret1++;
//             }
//         }
//     } //적록색약이아닌경우

//     init();

//     for(int i=0; i<n ; i++){
//         for(int j=0; j<n ; j++){
//             if(!visited[i][j]){
//                 bfs(i,j,false);
//                 ret2++;
//             }
//         }
//     } //적록색약인경우

//     cout<<ret1<<"\n"<<ret2<<"\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<vector<int>> MAP;
vector<vector<bool>> visited;
const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool isinside(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < n)
        return true;
    return false;
}
void Input()
{
    cin >> n;
    MAP.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            MAP[i][j] = str[j];
        }
    }
}
void bfs(bool flag, int y, int x, char color) //flag true면 적록색약
{
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push({y, x});
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!isinside(ny, nx))
                continue;
            if (visited[ny][nx] == true)
                continue;
            if (flag)
            {
                if (color == 'R' || color == 'G')
                {
                    if (MAP[ny][nx] == 'G' || MAP[ny][nx] == 'R')
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
                else
                {
                    if (MAP[ny][nx] == color)
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
            else
            {
                if (MAP[ny][nx] == color)
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}
int foo(bool flag)
{
    int Count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                Count++;
                bfs(flag, i, j, MAP[i][j]);
            }
        }
    }
    return Count;
}
void Solve()
{
    cout << foo(false) << endl;
    for (int i = 0; i < n; i++)
    {
        fill(visited[i].begin(), visited[i].end(), false);
    }
    cout << foo(true) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}