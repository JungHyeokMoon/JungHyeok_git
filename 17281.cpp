// #include <bits/stdc++.h>
// using namespace std;
// int n;
// int baseball[50][9];
// bool selected[9];
// int batting_order[9];
// int ret = -987654321;
// void Input()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             cin >> baseball[i][j];
//         }
//     }
//     batting_order[3] = 0;
//     selected[3] = true;
// }
// void Game()
// {
//     int base[3];
//     int Score = 0;
//     int Start_Player = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int outcnt = 0;
//         memset(base, false, sizeof(base));
//         while (1)
//         {
//             if (baseball[i][batting_order[Start_Player]] == 0)
//             {
//                 outcnt++;
//             }
//             else if (baseball[i][batting_order[Start_Player]] == 1)
//             {
//                 for (int k = 2; k >= 0; k--)
//                 {
//                     if (base[k] == 1)
//                     {
//                         if (k == 2)
//                         {
//                             base[k] = 0;
//                             Score++;
//                         }
//                         else
//                         {
//                             base[k + 1] = 1;
//                             base[k] = 0;
//                         }
//                     }
//                 }
//                 base[0] = 1;
//             }
//             else if (baseball[i][batting_order[Start_Player]] == 2)
//             {
//                 for (int k = 2; k >= 0; k--)
//                 {
//                     if (base[k] == 1)
//                     {
//                         if (k == 2 || k == 1)
//                         {
//                             base[k] = 0;
//                             Score++;
//                         }
//                         else
//                         {
//                             base[k + 2] = 1;
//                             base[k] = 0;
//                         }
//                     }
//                 }
//                 base[1] = 1;
//             }
//             else if (baseball[i][batting_order[Start_Player]] == 3)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     if (base[k] == 1)
//                     {
//                         base[k] = 0;
//                         Score++;
//                     }
//                 }
//                 base[2] = 1;
//             }
//             else
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     if (base[k] == 1)
//                     {
//                         base[k] = 0;
//                         Score++;
//                     }
//                 }
//                 Score++;
//             }
//             Start_Player = (Start_Player + 1) % 9;
//             if (outcnt == 3)
//             {
//                 break;
//             }
//         }
//     }

//     ret = max(ret, Score);
// }
// void Make_Batting_order(int playernum)
// {
//     if (playernum == 9)
//     {
//         Game();
//         return;
//     }

//     for (int i = 0; i < 9; i++)
//     {
//         if (selected[i])
//             continue;
//         selected[i] = true;
//         batting_order[i] = playernum;
//         Make_Batting_order(playernum + 1);
//         selected[i] = false;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     Input();
//     Make_Batting_order(1);
//     cout << ret << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<int>> baseball;
vector<int> batter;
int ret = -1e9;
void Init()
{
    cin >> n;
    baseball.resize(n, vector<int>(9));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            cin >> baseball[i][j];
    for (int i = 1; i < 9; i++)
        batter.push_back(i);
}
int Play()
{
    batter.insert(batter.begin()+3,0);
    int score = 0;
    int j = 0; //게임시작은 1번타자부터하니깐
    for (int i = 0; i < n; i++)
    {                                //이닝수만큼 게임진행
        vector<bool> base(3, false); //베이스 설정
        int out = 0;                 //아웃카운트
        while (1)
        { 
            int Player = batter[j];
            if (baseball[i][Player] == 0)
            {
                if (++out == 3)
                {
                    if (++j == 9)
                        j = j % 9;
                    break;
                }
            }
            else if (baseball[i][Player] == 1)
            { //안타친경우
                if (base[2])
                {
                    score++;
                    base[2] = false;
                } //3루에 주자가있다면 득점
                for (int i = 2; i >= 1; i--)
                {
                    if (base[i - 1])
                    {
                        base[i] = true; //1루씩전진
                        base[i - 1] = false;
                    }
                }
                base[0] = true; //1루로 진출
            }
            else if (baseball[i][Player] == 2)
            { //2루타
                for (int i = 2; i >= 1; i--)
                {
                    if (base[i])
                    {
                        score++;
                        base[i] = false;
                    }
                } //득점
                if (base[0])
                {
                    base[2] = true;
                    base[0] = false;
                }               //주자이동
                base[1] = true; //2루진출
            }
            else if (baseball[i][Player] == 3)
            { //3루타
                for (int i = 0; i < 3; i++)
                {
                    if (base[i])
                    {
                        score++;
                        base[i] = false;
                    }
                }
                base[2] = true; //3루진출
            }
            else
            { //홈런
                for (int i = 0; i < 3; i++)
                {
                    if (base[i])
                    {
                        score++;
                        base[i] = false;
                    }
                } //득점만
                score++; //타점
            }
            if (++j == 9)
                j = j % 9; //다음타자 데려와야하는데 9가 넘어가면 런타임오류 나지않게 처리해줌
        }
    }
    batter.erase(batter.begin()+3);
    return score;
}
void Solve()
{
    int cnt = 0;
    do
    {
        ret = max(ret, Play());
    } while (next_permutation(batter.begin(), batter.end()));
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