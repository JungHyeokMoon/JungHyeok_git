#include <bits/stdc++.h>
using namespace std;
int n, m;
char beads[10][10];

bool isvisited[10][10][10][10];
typedef struct Stat
{
    int ry, rx, by, bx, cnt;
} Stat;
int ry, rx, by, bx;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void inputfunc()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            beads[i][j] = temp[j];
            if (beads[i][j] == 'R')
            {
                ry = i;
                rx = j;
            }
            else if (beads[i][j] == 'B')
            {
                by = i;
                bx = j;
            }
        }
    }
}

int bfs()
{
    queue<Stat> q;
    q.push({ry, rx, by, bx, 0});
    isvisited[ry][rx][by][bx] = true;

    while (!q.empty())
    {

        Stat now = q.front();
        q.pop();

        if (beads[now.ry][now.rx] == 'O')
        {
            return now.cnt;
        }
        for (int i = 0; i < 4; i++)
        {
            int nry = now.ry;
            int nrx = now.rx;
            int nby = now.by;
            int nbx = now.bx;
            int cr = 0;
            int br = 0;
            while (beads[nry + dy[i]][nrx + dx[i]] != '#' && beads[nry][nrx] != 'O')
            {
                nry += dy[i];
                nrx += dx[i];
                cr++;
            }
            while (beads[nby + dy[i]][nbx + dx[i]] != '#' && beads[nby][nbx] != 'O')
            {
                nby += dy[i];
                nbx += dx[i];
                br++;
            }
            if(beads[nby][nbx]=='O'){
                continue;
            }
            if(nry==nby && nrx==nbx){
                if(cr>br){
                    nry-=dy[i];
                    nrx-=dx[i];
                }
                else{
                    nby-=dy[i];
                    nbx-=dx[i];
                }
            }
            if(isvisited[nry][nrx][nby][nbx])continue;
            if(now.cnt<10){
                isvisited[nry][nrx][nby][nbx]=true;
                q.push({nry,nrx,nby,nbx,now.cnt+1});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inputfunc();

    cout << bfs() << "\n";

    return 0;
}