// #include <bits/stdc++.h>
// using namespace std;
// int L,R,C;
// const int MAX=30;
// char building[MAX][MAX][MAX];
// typedef struct pos{
//     int x,y,z;
// }pos ;
// pos start,endp;
// bool visited[MAX][MAX][MAX];
// void init(){
//     for(int k=0; k<L; k++){
//         for(int i=0; i<R; i++){
//             fill(building[k][i],building[k][i]+C,false);
//         }
//     }
//     for(int k=0; k<L; k++){
//         for(int i=0; i<R; i++){
//             fill(visited[k][i],visited[k][i]+C,false);
//         }
//     }
// }
// int dz[]={1,-1,0,0,0,0};
// int dy[]={0,0,0,1,0,-1};
// int dx[]={0,0,-1,0,1,0};

// bool isinside(int z,int y, int x){
//     if(z>=0 && z<L && y>=0 && y<R && x>=0 && x<C)
//         return true;
//     return false;
// }

// void bfs(int z, int y, int x){
//     queue<pair<pair<int,int>,pair<int,int>>> q;

//     visited[z][y][x]=true;
//     q.push({{y,x},{z,0}});

//     while(!q.empty()){
//         int hy=q.front().first.first;
//         int hx=q.front().first.second;
//         int hz=q.front().second.first;
//         int hd=q.front().second.second;
//         q.pop();

//         if(hz==endp.z && hy==endp.y && hx==endp.x){
//             cout<<"Escaped in "<<hd<<" "<<"minute(s)."<<"\n";
//             return;
//         }
//         for(int i=0; i<6; i++){
//             int ny=hy+dy[i];
//             int nx=hx+dx[i];
//             int nz=hz+dz[i];
//             if(isinside(nz,ny,nx)&&!visited[nz][ny][nx]&&(building[nz][ny][nx]=='.'||building[nz][ny][nx]=='E')){
//                 visited[nz][ny][nx]=true;
//                 q.push({{ny,nx},{nz,hd+1}});
//             }
//         }
//     }
//     cout<<"Trapped!"<<"\n";
//     return ;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     while(1){
//         cin>>L>>R>>C;
//         if(L==0 && R==0 && C==0)return 0;
//         init();
//         for(int k=0; k<L; k++){
//             for(int i=0; i<R; i++){
//                 for(int j=0; j<C; j++){
//                     cin>>building[k][i][j];
//                     if(building[k][i][j]=='S'){
//                         start.z=k;
//                         start.y=i;
//                         start.x=j;
//                     }
//                     else if(building[k][i][j]=='E'){
//                         endp.z=k;
//                         endp.y=i;
//                         endp.x=j;
//                     }
//                 }
//             }
//         }
//         bfs(start.z,start.y,start.x);
//     }

//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int dz[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {0, 0, 0, 0, -1, 1};
char building[30][30][30] = {};
int dist[30][30][30];
typedef struct pos
{
    int z, y, x;

} pos;
pos Coordi[2];
int l, r, c;
bool IsinSide(int z, int y, int x)
{
    if (z >= 0 && z < l && y >= 0 && y < r && x >= 0 && x < c)
        return true;
    return false;
}
void Init()
{
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0)
        exit(0);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                dist[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cin >> building[i][j][k];
                if (building[i][j][k] == 'S')
                {
                    Coordi[0] = {i, j, k};
                }
                else if (building[i][j][k] == 'E')
                {
                    Coordi[1] = {i, j, k};
                }
            }
        }
    }
}
void bfs(int z, int y, int x)
{
    queue<pair<int, pair<int, int>>> q;
    dist[z][y][x] = 0;
    q.push({z, {y, x}});
    while (!q.empty())
    {
        auto cur = q.front();
        int hz = cur.first;
        int hy = cur.second.first;
        int hx = cur.second.second;
        q.pop();

        if (hz == Coordi[1].z && hy == Coordi[1].y && hx == Coordi[1].x)
        {
            cout << "Escaped in " << dist[hz][hy][hx] << " minute(s)." << endl;
            return;
        }

        for (int i = 0; i < 6; i++)
        {
            int nz = hz + dz[i];
            int ny = hy + dy[i];
            int nx = hx + dx[i];
            if (!IsinSide(nz, ny, nx))
                continue;
            if (dist[nz][ny][nx] >= 0)
                continue;
            if (building[nz][ny][nx] == '.' || building[nz][ny][nx] == 'E')
            {
                q.push({nz, {ny, nx}});
                dist[nz][ny][nx] = dist[hz][hy][hx] + 1;
            }
        }
    }
    cout << "Trapped!" << endl;
}
void Solve()
{
    while (1)
    {
        Init();
        bfs(Coordi[0].z, Coordi[0].y, Coordi[0].x);
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