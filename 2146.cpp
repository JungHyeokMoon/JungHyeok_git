// // #include <bits/stdc++.h>
// // using namespace std;
// // int n;
// // const int MAX=100;
// // int dy[4]={0,-1,0,1};
// // int dx[4]={1,0,-1,0};
// // bool isinside(int y, int x){
// //     if(y>=0 && y<n && x>=0 && x<n){
// //         return true;
// //     }
// //     return false;
// // }
// // int bridge[MAX][MAX];
// // bool visited[MAX][MAX];

// // void input(){
// //     cin>>n;
// //     for(int i=0; i<n ; i++){
// //         for(int j=0; j<n; j++){
// //             cin>>bridge[i][j];
// //             if(bridge[i][j]==1)bridge[i][j]=-1;
// //         }
// //     }
// // }
// // void makeland(int y, int x,int l){
// //     visited[y][x]=true;
// //     queue<pair<int,int>> q;
// //     q.push({y,x});
// //     bridge[y][x]=l;
// //     while(!q.empty()){
// //         int hy=q.front().first;
// //         int hx=q.front().second;
// //         q.pop();

// //         for(int i=0; i<4; i++){
// //             int ny=hy+dy[i];
// //             int nx=hx+dx[i];
// //             if(isinside(ny,nx)&&!visited[ny][nx]&&bridge[ny][nx]==-1){
// //                 visited[ny][nx]=true;
// //                 bridge[ny][nx]=l;
// //                 q.push({ny,nx});
// //             }
// //         }
// //     }
// // }
// // int ret=987654321;

// // int bfs(int L){
// //     queue<pair<int,int>>q;
// //     for(int i=0; i<n; i++){
// //         for(int j=0; j<n; j++){
// //             if(bridge[i][j]==L){
// //                 q.push({i,j});
// //                 visited[i][j]=true;
// //             }
// //         }
// //     }

// //     int result=0;
// //     while(!q.empty()){
// //         int qsize=q.size();
// //         for(int i=0; i<qsize; i++){
// //             int hy=q.front().first;
// //             int hx=q.front().second;
// //             q.pop();

// //             for(int j=0; j<4; j++){
// //                 int ny=hy+dy[j];
// //                 int nx=hx+dx[j];
// //                 if(!isinside(ny,nx))continue;

// //                 if(bridge[ny][nx]!=L&&bridge[ny][nx]!=0)return result;
// //                 if(visited[ny][nx])continue;
// //                 if(bridge[ny][nx]==0){
// //                     q.push({ny,nx});
// //                     visited[ny][nx]=true;
// //                 }
// //             }
// //         }
// //         result++;
// //     }
// // }
// // int main(){
// //     ios::sync_with_stdio(false);
// // 	cin.tie(NULL);
// //     input();
// //     int Land=1;
// //     for(int i=0; i<n; i++){
// //         for(int j=0; j<n; j++){
// //             if(!visited[i][j]&&bridge[i][j]==-1){
// //                 makeland(i,j,Land);
// //                 Land++;
// //             }
// //         }
// //     }

// //     for(int i=1; i<Land; i++){
// //         memset(visited,false,sizeof(visited));
// //         ret=min(ret,bfs(i));
// //     }

// //     cout<<ret<<"\n";
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"

// int ret = 1e9;
// int n;
// const pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// vector<vector<int>> MAP;
// vector<vector<bool>> visited;
// bool Isinside(int y, int x)
// {
//     if (y >= 0 && y < n && x >= 0 && x < n)
//         return true;
//     return false;
// }
// void Init()
// {
//     cin >> n;
//     MAP.resize(n, vector<int>(n));
//     visited.resize(n, vector<bool>(n, false));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> MAP[i][j];
//         }
//     }
// }
// bool zeroCheck(int y, int x)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         int ny = y + d[i].first;
//         int nx = x + d[i].second;
//         if (!Isinside(ny, nx))
//             continue;
//         if (MAP[ny][nx] == 0)
//             return true;
//     }
//     return false;
// }
// void landCheck(int y, int x, int color)
// {
//     MAP[y][x] = color;
//     queue<pair<int, int>> q;
//     queue<pair<pair<int, int>, int>> connectQ;
//     visited[y][x] = true;
//     q.push({y, x});
//     while (!q.empty())
//     {
//         auto cur = q.front();
//         int hy = cur.first;
//         int hx = cur.second;
//         if (zeroCheck(hy, hx))
//             connectQ.push({{hy, hx}, 0});
//         q.pop();

//         for (int i = 0; i < 4; i++)
//         {
//             int ny = hy + d[i].first;
//             int nx = hx + d[i].second;
//             if (!Isinside(ny, nx))
//                 continue;
//             if (visited[ny][nx] == true)
//                 continue;
//             if (MAP[ny][nx] == 1)
//             {
//                 q.push({ny, nx});
//                 visited[ny][nx] = true;
//                 MAP[ny][nx] = color;
//             }
//         }
//     }

//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         cout << MAP[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // cout << endl;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         cout << visited[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // cout << endl;

//     vector<vector<bool>> cVisited = visited;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         cout << cVisited[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // cout << endl;
//     // cout << color << endl;
//     while (!connectQ.empty())
//     {
//         auto cur = connectQ.front();
//         int hy = cur.first.first;
//         int hx = cur.first.second;
//         int t = cur.second;
//         // cout << "hy : " << hy << " , hx : " << hx << " , t : " << t << endl;
//         connectQ.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = hy + d[i].first;
//             int nx = hx + d[i].second;
//             if (!Isinside(ny, nx))
//                 continue;
//             if (cVisited[ny][nx])
//                 continue;
//             if (MAP[ny][nx] == 0 && cVisited[ny][nx] == false)
//             {
//                 connectQ.push({{ny, nx}, t + 1});
//                 cVisited[ny][nx] = true;
//                 continue;
//             }
//             if (MAP[ny][nx] != color)
//             {
//                 ret = min(ret, t);
//                 return;
//             }
//         }
//     }
//     // cout << endl
//     //      << endl;
// }
// void Solve()
// {
//     int color = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (MAP[i][j] == 1 && visited[i][j] == false)
//             {
//                 landCheck(i, j, ++color);
//             }
//         }
//     }
//     cout << ret << endl;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Init();
//     Solve();
//     return 0;
// }