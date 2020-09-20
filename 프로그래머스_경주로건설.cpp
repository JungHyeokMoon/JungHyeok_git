#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> cost;
int cost [4][25][25]={0};
pair<int, int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 오른, 아래,위, 왼쪽
int N;
//직선도로 100원, 코너 500원
int answer = 1e9;
bool Isinside(int y, int x)
{
    if (y >= 0 && y < N && x >= 0 && x < N)
        return true;
    return false;
}
int solution(vector<vector<int>> board)
{

    N = board.size();
    
    for(int i=0; i<4; i++){
        for(int j=0; j<25; j++){
            for(int k=0; k<25; k++){
                cost[i][j][k]=1e9;
            }
        }
    }
    cost[0][0][0] = 0;
    cost[1][0][0] = 0;
    cost[2][0][0] = 0;
    cost[3][0][0] = 0;
    queue<tuple<int, int, int>> q; //현재방향, hy,hx
    //0 오른 , 1 아래, 2 위,3왼쪽
    if (board[0][1] == 0)
    {
        cost[0][0][1] = 100;
        q.push(make_tuple(0, 0, 1));
    }
    if (board[1][0] == 0)
    {
        cost[1][1][0] = 100;
        q.push(make_tuple(1, 1, 0));
    }

    while (!q.empty())
    {
        int hd, hy, hx;
        tie(hd, hy, hx) = q.front();
        q.pop();

        // cout << "hd :" << hd << " hy: " << hy << " hx: " << hx << " cost : " << cost[hy][hx] << endl;
        if (hy == N - 1 && hx == N - 1)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = hy + dir[i].first;
            int nx = hx + dir[i].second;

            if (!Isinside(ny, nx))
                continue;
            if (board[ny][nx] == 1)
                continue;

            //0 오른 , 1 아래, 2 위,3왼쪽
            int nextcost = 0;
            if (hd == 0 || hd == 3)
            {
                if (i == 0 || i == 3)
                    nextcost = cost[hd][hy][hx] + 100;
                else if (i == 1 || i == 2)
                    nextcost = cost[hd][hy][hx] + 100 + 500;
            }
            else if (hd == 1 || hd == 2)
            {
                if (i == 0 || i == 3)
                    nextcost = cost[hd][hy][hx] + 100 + 500;
                else if (i == 1 || i == 2)
                    nextcost = cost[hd][hy][hx] + 100;
            }

            if (nextcost < cost[i][ny][nx])
            {
                cost[i][ny][nx] = nextcost;
                q.push(make_tuple(i, ny, nx));
            }
        }
    }
    for(int i=0; i<4; i++)
        answer=min(answer,cost[i][N-1][N-1]);
    
    
    return answer;
}

int main()
{
    cout << solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) << endl;
    // cout << solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}});
    // cout << solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}}) << endl;
    // cout << solution({{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}}) << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<bool>> visited;
// pair<int, int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 오른, 아래,위, 왼쪽
// int N;
// //직선도로 100원, 코너 500원
// int answer = 1e9;
// bool Isinside(int y, int x)
// {
//     if (y >= 0 && y < N && x >= 0 && x < N)
//         return true;
//     return false;
// }
// int solution(vector<vector<int>> board)
// {

//     N = board.size();
//     visited.resize(N, vector<bool>(N, false));

//     visited[0][0] = true;
//     queue<tuple<int, int, int, int, int>> q; //현재방향, hy,hx,straight, corner
//     if (board[0][1] == 0)
//     {
//         visited[0][1] = true;
//         q.push(make_tuple(0, 0, 1, 1, 0));
//     }
//     if (board[1][0] == 0)
//     {
//         visited[1][0] = true;
//         q.push(make_tuple(1, 1, 0, 1, 0));
//     }

//     while (!q.empty())
//     {
//         int hd, hy, hx, straight, corner;
//         tie(hd, hy, hx, straight, corner) = q.front();
//         q.pop();

//         if (hy == N - 1 && hx == N - 1)
//         {
//             answer = min(answer, straight * 100 + corner * 500);
//             continue;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             int ny = hy + dir[i].first;
//             int nx = hx + dir[i].second;

//             if (!Isinside(ny, nx))
//                 continue;
//             if (visited[ny][nx])
//                 continue;
//             if (board[ny][nx] == 1)
//                 continue;
//             visited[ny][nx] = true;
//             //0 오른 , 1 아래, 2 위,3왼쪽
//             if (hd == 0 || hd == 3)
//             {
//                 if (i == 0)
//                 {
//                     q.push(make_tuple(i, ny, nx, straight + 1, corner));
//                 }
//                 else if (i == 1)
//                 {
//                     q.push(make_tuple(i, ny, nx, straight+1, corner + 1));
//                 }
//                 else if (i == 2)
//                 {
//                     q.push(make_tuple(i, ny, nx, straight+1, corner + 1));
//                 }
//                 else
//                 {
//                     q.push(make_tuple(i, ny, nx, straight + 1, corner));
//                 }
//             }
//             else if (hd == 1 || hd == 2)
//             {
//                 if (i == 0)
//                 {
//                     q.push(make_tuple(i, ny, nx, straight+1, corner + 1));
//                 }
//                 else if (i == 1)
//                 {
//                     q.push(make_tuple(i, ny, nx, straight + 1, corner));
//                 }
//                 else if (i == 2)
//                 {
//                     q.push(make_tuple(i, ny, nx, straight + 1, corner));
//                 }
//                 else
//                 {
//                     q.push(make_tuple(i, ny, nx, straight+1, corner + 1));
//                 }
//             }
//         }
//     }
//     return answer;
// }