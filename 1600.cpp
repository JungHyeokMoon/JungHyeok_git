// #include <bits/stdc++.h>
// using namespace std;

// const int MAX=200;
// int K;
// int W,H;
// bool isinside(int y, int x){
//     if(y>=0 && y<H && x>=0 && x<W){
//         return true;
//     }
//     return false;
// }
// int dy[4]={0,-1,0,1};
// int dx[4]={1,0,-1,0};
// bool isvisted[MAX][MAX][31];
// int diagonaldy[8]={-1,-2,-2,-1,1,2,2,1};
// int diagonaldx[8]={-2,-1,1,2,2,1,-1,-2};
// int monkey[MAX][MAX];

// int ret=-1;

// typedef struct Solve{
//     int y,x,k,t;
// }Solve;
// int bfs(int y, int x){
//     queue<Solve> q;
//     isvisted[y][x][0]=true;
//     q.push({y,x,0,0});

//     while(!q.empty()){
//         int hy=q.front().y;
//         int hx=q.front().x;
//         int hk=q.front().k;
//         int ht=q.front().t;
//         //cout<<"hy : "<<hy<<" , "<<"hx : "<<hx<<" , "<<"hk : "<<hk<<" , "<<"ht : "<<ht<<"\n";
//         q.pop();
//         if(hy==H-1 &&hx==W-1)return ht;

//         if(hk<K){
//             for(int i=0; i<8; i++){
//                 int ny=hy+diagonaldy[i];
//                 int nx=hx+diagonaldx[i];
//                 if(!isinside(ny,nx))continue;

//                 if(monkey[ny][nx]==0&&!isvisted[ny][nx][hk+1]){
//                     isvisted[ny][nx][hk+1]=true;

//                     q.push({ny,nx,hk+1,ht+1});
//                 }
//             }
//         }
//         for(int i=0; i<4; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             if(!isinside(ny,nx))continue;

//             if(monkey[ny][nx]==0&&!isvisted[ny][nx][hk]){
//                 isvisted[ny][nx][hk]=true;

//                 q.push({ny,nx,hk,ht+1});
//             }
//         }
//     }

//     return -1;
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>K;
//     cin>>W>>H;

//     for(int i=0; i<H; i++){
//         for(int j=0; j<W; j++){
//             cin>>monkey[i][j];
//         }
//     }

//     cout<<bfs(0,0)<<"\n";
//     return 0;
// }
// //조건이 주어져있는경우는 3차원배열을생각해봐야함

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int k, w, h;
vector<vector<int>> MAP;
int dist[31][200][200];
bool isInside(int y, int x)
{
    if (y >= 0 && y < h && x >= 0 && x < w)
        return true;
    return false;
}
pair<int, int> horse[8] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};
pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void Init()
{
    cin >> k >> w >> h;
    MAP.resize(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                dist[i][j][k] = -1;
            }
        }
    }
}
void Solve()
{
    dist[0][0][0] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    while (!q.empty())
    {
        auto cur = q.front();
        int hc = cur.first;
        int hy = cur.second.first;
        int hx = cur.second.second;
        // cout << "hc : " << hc << " , hy : " << hy << " , hx : " << hx << endl;
        q.pop();
        if (hy == h - 1 && hx == w - 1)
        {
            cout << dist[hc][hy][hx] << endl;
            return;
        }
        if (hc != k)
        {
            for (int i = 0; i < 8; i++)
            {
                int ny = hy + horse[i].first;
                int nx = hx + horse[i].second;
                if (!isInside(ny, nx))
                {
                    // cout << "here1" << endl;
                    continue;
                }
                if (dist[hc + 1][ny][nx] >= 0)
                {
                    // cout << "here2" << endl;
                    continue;
                }
                if (MAP[ny][nx] == 1)
                {
                    // cout << "here3" << endl;
                    continue;
                }

                dist[hc + 1][ny][nx] = dist[hc][hy][hx] + 1;
                q.push({hc + 1, {ny, nx}});
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = hy + d[i].first;
            int nx = hx + d[i].second;
            if (!isInside(ny, nx))
                continue;
            if (dist[hc][ny][nx] >= 0)
                continue;
            if (MAP[ny][nx] == 1)
                continue;

            dist[hc][ny][nx] = dist[hc][hy][hx] + 1;
            q.push({hc, {ny, nx}});
        }
    }
    cout << -1 << endl;
    return;
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