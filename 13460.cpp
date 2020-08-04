// #include <bits/stdc++.h>
// using namespace std;
// int n, m;
// char beads[10][10];

// bool isvisited[10][10][10][10];
// typedef struct Stat
// {
//     int ry, rx, by, bx, cnt;
// } Stat;
// int ry, rx, by, bx;

// int dy[4] = {-1, 0, 1, 0};
// int dx[4] = {0, 1, 0, -1};
// void inputfunc()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         string temp;
//         cin >> temp;
//         for (int j = 0; j < m; j++)
//         {
//             beads[i][j] = temp[j];
//             if (beads[i][j] == 'R')
//             {
//                 ry = i;
//                 rx = j;
//             }
//             else if (beads[i][j] == 'B')
//             {
//                 by = i;
//                 bx = j;
//             }
//         }
//     }
// }

// int bfs()
// {
//     queue<Stat> q;
//     q.push({ry, rx, by, bx, 0});
//     isvisited[ry][rx][by][bx] = true;

//     while (!q.empty())
//     {

//         Stat now = q.front();
//         q.pop();

//         if (beads[now.ry][now.rx] == 'O')
//         {
//             return now.cnt;
//         }
//         for (int i = 0; i < 4; i++)
//         {
//             int nry = now.ry;
//             int nrx = now.rx;
//             int nby = now.by;
//             int nbx = now.bx;
//             int cr = 0;
//             int br = 0;
//             while (beads[nry + dy[i]][nrx + dx[i]] != '#' && beads[nry][nrx] != 'O')
//             {
//                 nry += dy[i];
//                 nrx += dx[i];
//                 cr++;
//             }
//             while (beads[nby + dy[i]][nbx + dx[i]] != '#' && beads[nby][nbx] != 'O')
//             {
//                 nby += dy[i];
//                 nbx += dx[i];
//                 br++;
//             }
//             if(beads[nby][nbx]=='O'){
//                 continue;
//             }
//             if(nry==nby && nrx==nbx){
//                 if(cr>br){
//                     nry-=dy[i];
//                     nrx-=dx[i];
//                 }
//                 else{
//                     nby-=dy[i];
//                     nbx-=dx[i];
//                 }
//             }
//             if(isvisited[nry][nrx][nby][nbx])continue;
//             if(now.cnt<10){
//                 isvisited[nry][nrx][nby][nbx]=true;
//                 q.push({nry,nrx,nby,nbx,now.cnt+1});
//             }
//         }
//     }
//     return -1;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     inputfunc();

//     cout << bfs() << "\n";

//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<vector<char>> MAP;
pair<int, int> Point[3];                                    //0출구 1 레드 2 블루
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //위 오른쪽 아래 왼쪽

int Turn[10];
int ret = 1e9;
bool Check(pair<int, int> P, int d)
{
    while (1)
    {
        int ny = P.first + dir[d].first;
        int nx = P.second + dir[d].second;
        if (ny == Point[0].first && nx == Point[0].second)
            return false;
        else if (MAP[ny][nx] == '#')
            return true;
        P = {ny, nx};
    }
}

int tilt()
{
    pair<int, int> R = Point[1];
    pair<int, int> B = Point[2];
    for (int i = 0; i < 10; i++)
    {
        int d = Turn[i];
        // cout << "direction : " << d << endl;
        while (1)
        {
            int Rny = R.first + dir[d].first;
            int Rnx = R.second + dir[d].second;

            int Bny = B.first + dir[d].first;
            int Bnx = B.second + dir[d].second;
            if (Rny == Point[0].first && Rnx == Point[0].second) //빨간공이 도착하고나서 Check로 파란공이 들어오냐 안들어오냐 체크
                return Check(B, d) == true ? i + 1 : 1e9;

            else if (Bny == Point[0].first && Bnx == Point[0].second)
                return 1e9; //파란공이먼저도착한경우

            if (MAP[Rny][Rnx] != '#' && !(Rny == B.first && Rnx == B.second))
                R = {Rny, Rnx};
            if (MAP[Bny][Bnx] != '#' && !(Bny == R.first && Bnx == R.second))
                B = {Bny, Bnx};

            if (!(R.first == Rny && R.second == Rnx) && !(B.first == Bny && B.second == Bnx))
            {
                // cout << "hi" << endl;
                break; //둘다움직이지않는경우
            }
        }
    }
    return 1e9;
}
void MakeTurn(int cnt)
{
    if (cnt == 10)
    {
        ret = min(ret, tilt());
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        Turn[cnt] = i;
        MakeTurn(cnt + 1);
    }
}
void Init()
{
    cin >> n >> m;
    MAP.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            MAP[i][j] = temp[j];
            if (MAP[i][j] == 'O')
                Point[0] = {i, j};
            else if (MAP[i][j] == 'R')
                Point[1] = {i, j};
            else if (MAP[i][j] == 'B')
                Point[2] = {i, j};
        }
    }
}
void Solve()
{
    MakeTurn(0);
    if (ret == 1e9)
        cout << -1 << endl;
    else
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