#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int game[20][20];
int c_game[20][20];
int order[5];
int ret = -987654321;
//up 0 left 1 down 2 right 3
queue<int> q;
void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> game[i][j];
        }
    }
}
void Copy_Map()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c_game[i][j] = game[i][j];
        }
    }
}
void get(int y, int x)
{
    if (c_game[y][x])
    {
        q.push(c_game[y][x]);
        c_game[y][x] = 0;
    }
}
void merge(int y, int x, int dy, int dx)
{
    while (!q.empty())
    {
        int value = q.front();
        q.pop();
        if (c_game[y][x] == 0)
        {
            c_game[y][x] = value;
        }//0이면 큐에꺼내서놓고
        else if (c_game[y][x] == value)
        {
            c_game[y][x] =value*2;
            y += dy;
            x += dx;
        }//같을경우 두배
        else
        {
            y += dy;
            x += dx;
            c_game[y][x] = value;
        }//아니면 인덱스증가시켜서 값을놓는다.
    }
}
void Move(int d)
{
    if (d == 0)
    { //방향위
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                get(j, i);
            }
            merge(0, i, 1, 0);
        }
    }
    else if (d == 1)
    { //왼쪽
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                get(i, j);
            }
            merge(i, 0, 0, 1);
        }
    }
    else if (d == 2)
    { //아래
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                get(i,j);
            }
            merge(n-1,j,-1,0);
        }
    }
    else
    { //오른쪽
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                get(i,j);
            }
            merge(i,n-1,0,-1);
        }
    }
}
int RetMaxscore() //최댓값탐색
{
    int score = -987654321;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            score = max(score, c_game[i][j]);
        }
    }
    return score;
}
void Solve()
{
    for (int i = 0; i < 5; i++)
    {
        int dir = order[i];
        Move(dir);
    }
    int score=RetMaxscore();
    ret = max(ret, score);
    // for(int i=0; i<5; i++){
    //     cout<<order[i]<<" ";
    // }
    // cout<<"score : "<<score<<" ret : "<<ret<<endl;
    // cout<<ret<<endl;
    return ;
}
void MakeOrder(int cnt)
{
    if (cnt == 5)
    {
        Copy_Map();
        Solve();
        return;
    }
    //중복순열을 만들어야함
    for (int i = 0; i < 4; i++)
    {
        order[cnt] = i;
        MakeOrder(cnt + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    MakeOrder(0);
    cout << ret << endl;
    return 0;
}