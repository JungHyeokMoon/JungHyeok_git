#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool isvisited[1000][1000];
int c, r, k, d; //가로가 c ,세로 r
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int cnt = 0;
bool isinside(int x, int y)
{
    if (x >= 0 && x < c && y >= 0 && y < r)
    {
        return true;
    }
    return false;
}
void Input()
{
    cin >> c >> r >> k;
}
void Solve(pair<int, int> hc, int direc)
{
    int hx = hc.first;
    int hy = hc.second;
    isvisited[hx][hy] = true;
    cnt++;
    // cout << "hx : " << hx+1 << ","
    //      << "hy : " << hy+1 << ", direc:" << direc <<"cnt : "<<cnt <<endl;
    if (cnt == k)
    {
        cout <<hx+1 << " " << hy+1 << endl;
        return;
    }
    int nx = hx + dir[direc][0];
    int ny = hy + dir[direc][1];
    if (!isinside(nx, ny)||isvisited[nx][ny])
    {
        nx=nx-dir[direc][0];
        ny=ny-dir[direc][1];
        direc=(direc+1)%4;
        nx=nx+dir[direc][0];
        ny=ny+dir[direc][1];
    }
    Solve({nx, ny}, direc);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    if (k > c * r)
    {
        cout << 0 << endl;
    }
    else
    {
        Solve({0, 0}, 0);
    }
    return 0;
}