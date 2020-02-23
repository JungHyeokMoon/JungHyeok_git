#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int R, C;
char Miro[50][50];
typedef struct Pos
{
    int y, x;
} Pos;
bool isvisited[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool isinside(int y, int x)
{
    if (y >= 0 && y < R && x >= 0 && x < C)
    {
        return true;
    }
    return false;
}
Pos Start;
queue<pair<int, int>> water;
void MapPrint()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << Miro[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> Miro[i][j];
            if (Miro[i][j] == 'S')
            {
                Start.y = i;
                Start.x = j;
            }
            if (Miro[i][j] == '*')
            {
                water.push({i, j});
            }
        }
    }
}
void WaterBound()
{
    int watersize = water.size();
    for (int i = 0; i < watersize; i++)
    {
        int waterhy = water.front().first;
        int waterhx = water.front().second;
        water.pop();
        for (int j = 0; j < 4; j++)
        {
            int waterny = waterhy + dy[j];
            int waternx = waterhx + dx[j];
            if (!isinside(waterny, waternx))
                continue; //범위가 넘어가면 무시하고 다른거탐색
            if (Miro[waterny][waternx] == 'D')
                continue;
            if (!(Miro[waterny][waternx] == 'X' || Miro[waterny][waternx] == '*'))
            { //돌이나 이미 물이 아닌곳은 확장할수가있다.
                Miro[waterny][waternx] = '*';
                water.push({waterny, waternx});
            }
        }
    }
}
//고슴도치의 위치는 s, 비버의굴은 d ,돌은 x 비어있는곳 . 물이차있는지역 x
void bfs(int y, int x)
{
    isvisited[y][x] = true;
    queue<pair<pair<int, int>, int>> biber;
    biber.push({{y, x}, 0});
    while (!biber.empty())
    {
        //물확장
        WaterBound();
        // MapPrint();
        int bibersize = biber.size();
        for (int i = 0; i < bibersize; i++)
        {
            int hy = biber.front().first.first;
            int hx = biber.front().first.second;
            int ht = biber.front().second;
            // cout<<"hy : "<<hy<<", hx : "<<hx<<" , ht :"<<ht<<endl;
            biber.pop();
            // 마지막위치도달
            if (Miro[hy][hx] == 'D')
            {
                cout << ht << endl;
                return;
            }
            for (int j = 0; j < 4; j++)
            {
                int ny = hy + dy[j];
                int nx = hx + dx[j];
                if (!isinside(ny, nx))
                    continue;
                if (isvisited[ny][nx])
                    continue;
                if (!(Miro[ny][nx] == 'X' || Miro[ny][nx] == '*'))
                {
                    isvisited[ny][nx] = true;
                    biber.push({{ny, nx}, ht + 1});
                }
            }
        }
    }

    cout << "KAKTUS" << endl; //다돌았는데도 못찾은경우
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    bfs(Start.y, Start.x);
}