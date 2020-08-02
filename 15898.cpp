#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<vector<vector<pair<int, char>>>>> Ingredients;
vector<vector<pair<int, char>>> MAP;
vector<bool> visited;
int ret = -1e9;
void Rotate(int type, int dir)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Ingredients[type][dir][i][j] = Ingredients[type][dir - 1][4 - 1 - j][i];
        }
    }
}
void Init()
{
    cin >> n;
    MAP.resize(5, vector<pair<int, char>>(5, {0, 'W'}));
    visited.resize(n, false);
    Ingredients.resize(n, vector<vector<vector<pair<int, char>>>>(4));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            Ingredients[i][j].resize(4, vector<pair<int, char>>(4));
        vector<vector<pair<int, char>>> Ingredient(4, vector<pair<int, char>>(4));
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> Ingredient[i][j].first;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> Ingredient[i][j].second;
        Ingredients[i][0] = Ingredient;
    }
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 4; j++)
            Rotate(i, j);
}

int Cal(vector<vector<pair<int, char>>> MAP)
{
    int R = 0, B = 0, G = 0, Y = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (MAP[i][j].second == 'R')
                R += MAP[i][j].first;
            else if (MAP[i][j].second == 'B')
                B += MAP[i][j].first;
            else if (MAP[i][j].second == 'G')
                G += MAP[i][j].first;
            else if (MAP[i][j].second == 'Y')
                Y += MAP[i][j].first;
        }
    }
    return (R * 7 + B * 5 + G * 3 + Y * 2);
}
vector<vector<pair<int, char>>> SetIngredient(vector<vector<pair<int, char>>> MAP, int idx, int row, int col, int dir)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            MAP[i + row][j + col].first += Ingredients[idx][dir][i][j].first;
            if (MAP[i + row][j + col].first <= 0)
                MAP[i + row][j + col].first = 0;
            else if (MAP[i + row][j + col].first > 9)
                MAP[i + row][j + col].first = 9;

            if (Ingredients[idx][dir][i][j].second != 'W')
                MAP[i + row][j + col].second = Ingredients[idx][dir][i][j].second;
        }
    }

    return MAP;
}

void dfs(int cnt, vector<vector<pair<int, char>>> MAP)
{
    if (cnt == 3)
    {
        ret = max(ret, Cal(MAP));
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        vector<vector<pair<int, char>>> tmp = SetIngredient(MAP, i, j, k, l);
                        dfs(cnt + 1, tmp);
                    }
                }
            }
            visited[i] = false;
        }
    }
}
void Solve()
{
    dfs(0, MAP);
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

// for (int i = 0; i < n; i++)
// {
//     cout << i << ": th" << endl;
//     for (int j = 0; j < 4; j++)
//     {
//         cout << j << ": dir" << endl;
//         for (int k = 0; k < 4; k++)
//         {
//             for (int l = 0; l < 4; l++)
//             {
//                 cout << Ingredients[i][j][k][l].first
//                      << Ingredients[i][j][k][l].second << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     cout << "\\\\\\\\\\\\\\" << endl;
// }

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n;
// vector<vector<vector<vector<pair<int, char>>>>> Ingredients;
// // vector<int> permutation;
// // vector<int> point;
// // vector<int> rotation;
// vector<vector<pair<int, char>>> MAP;
// int ret = -1e9;
// void Rotate(int type, int dir)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             Ingredients[type][dir][i][j] = Ingredients[type][dir - 1][4 - 1 - j][i];
//         }
//     }
// }
// void Init()
// {
//     cin >> n;
//     // for (int i = 0; i < n; i++)
//     //     permutation.push_back(i);

//     // for (int i = 0; i < 12; i++)
//     // {
//     //     point.push_back(i % 4);
//     //     rotation.push_back(i % 4);
//     // }
//     // sort(point.begin(), point.end());
//     // sort(rotation.begin(), rotation.end());
//     MAP.resize(5, vector<pair<int, char>>(5, {0, 'W'}));
//     Ingredients.resize(n, vector<vector<vector<pair<int, char>>>>(4));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 4; j++)
//             Ingredients[i][j].resize(4, vector<pair<int, char>>(4));
//         vector<vector<pair<int, char>>> Ingredient(4, vector<pair<int, char>>(4));
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> Ingredient[i][j].first;

//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> Ingredient[i][j].second;
//         Ingredients[i][0] = Ingredient;
//     }
//     for (int i = 0; i < n; i++)
//         for (int j = 1; j < 4; j++)
//             Rotate(i, j);
// }

// int Cal(vector<vector<pair<int, char>>> MAP)
// {
//     int R = 0, B = 0, G = 0, Y = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (MAP[i][j].second == 'R')
//                 R += MAP[i][j].first;
//             else if (MAP[i][j].second == 'B')
//                 B += MAP[i][j].first;
//             else if (MAP[i][j].second == 'G')
//                 G += MAP[i][j].first;
//             else if (MAP[i][j].second == 'Y')
//                 Y += MAP[i][j].first;
//         }
//     }
//     return (R * 7 + B * 5 + G * 3 + Y * 2);
// }
// vector<vector<pair<int, char>>> SetIngredient(int P, int R, vector<vector<pair<int, char>>> MAP, int n)
// {
//     if (P == 0)
//     { //(0,0)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i][j].first += Ingredients[n][R][i][j].first;
//                 if (MAP[i][j].first < 0)
//                     MAP[i][j].first = 0;
//                 else if (MAP[i][j].first > 9)
//                     MAP[i][j].first = 9;
//                 if (Ingredients[n][R][i][j].second != 'W')
//                     MAP[i][j].second = Ingredients[n][R][i][j].second;
//             }
//         }
//     }
//     else if (P == 1)
//     { //(0,1)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i][j + 1].first += Ingredients[n][R][i][j].first;
//                 if (MAP[i][j + 1].first < 0)
//                     MAP[i][j + 1].first = 0;
//                 else if (MAP[i][j + 1].first > 9)
//                     MAP[i][j + 1].first = 9;
//                 if (Ingredients[n][R][i][j].second != 'W')
//                     MAP[i][j + 1].second = Ingredients[n][R][i][j].second;
//             }
//         }
//     }
//     else if (P == 2)
//     { //(1,0)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i + 1][j].first += Ingredients[n][R][i][j].first;
//                 if (MAP[i + 1][j].first < 0)
//                     MAP[i + 1][j].first = 0;
//                 else if (MAP[i + 1][j].first > 9)
//                     MAP[i + 1][j].first = 9;
//                 if (Ingredients[n][R][i][j].second != 'W')
//                     MAP[i + 1][j].second = Ingredients[n][R][i][j].second;
//             }
//         }
//     }
//     else
//     { //(1,1)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i + 1][j + 1].first += Ingredients[n][R][i][j].first;
//                 if (MAP[i + 1][j + 1].first < 0)
//                     MAP[i + 1][j + 1].first = 0;
//                 else if (MAP[i + 1][j + 1].first > 9)
//                     MAP[i + 1][j + 1].first = 9;
//                 if (Ingredients[n][R][i][j].second != 'W')
//                     MAP[i + 1][j + 1].second = Ingredients[n][R][i][j].second;
//             }
//         }
//     }
//     return MAP;
// }
// int getScore(vector<vector<pair<int, char>>> MAP)
// {

//     // for (int i = 0; i < 3; i++) // 3
//     // {
//     //     MAP = SetIngredient(point[i], rotation[i], MAP, permutation[i]);
//     // }

//     return Cal(MAP);
// }
// void Solve()
// {

//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << i << ": th" << endl;
//     //     for (int j = 0; j < 4; j++)
//     //     {
//     //         cout << j << ": dir" << endl;
//     //         for (int k = 0; k < 4; k++)
//     //         {
//     //             for (int l = 0; l < 4; l++)
//     //             {
//     //                 cout << Ingredients[i][j][k][l].first
//     //                      << Ingredients[i][j][k][l].second << " ";
//     //             }
//     //             cout << endl;
//     //         }
//     //         cout << endl;
//     //     }
//     //     cout << "\\\\\\\\\\\\\\" << endl;
//     // }
//     // do
//     // {
//     //     do
//     //     {
//     //         do
//     //         {
//     //             ret = max(ret, getScore(MAP));
//     //             reverse(rotation.begin() + 3, rotation.end());
//     //         } while (next_permutation(rotation.begin(), rotation.end())); //0도 90도 180도 270도 회전
//     //         reverse(point.begin() + 3, point.end());
//     //     } while (next_permutation(point.begin(), point.end())); //(0,0) (0,1) (1,0) (1,1) 4개중 어느위치
//     //     reverse(permutation.begin() + 3, permutation.end());
//     // } while (next_permutation(permutation.begin(), permutation.end()));

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

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n;
// vector<vector<vector<pair<int, char>>>> Ingredients;
// vector<int> permutation;
// vector<int> point;
// vector<int> rotation;
// vector<vector<pair<int, char>>> MAP;
// int ret = -1e9;
// void Init()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         permutation.push_back(i);

//     for (int i = 0; i < 12; i++)
//     {
//         point.push_back(i % 4);
//         rotation.push_back(i % 4);
//     }
//     sort(point.begin(), point.end());
//     sort(rotation.begin(), rotation.end());
//     MAP.resize(5, vector<pair<int, char>>(5, {0, 'W'}));
//     for (int i = 0; i < n; i++)
//     {
//         vector<vector<pair<int, char>>> Ingredient(4, vector<pair<int, char>>(4));
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> Ingredient[i][j].first;

//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> Ingredient[i][j].second;

//         Ingredients.push_back(Ingredient);
//     }
// }
// int Cal(vector<vector<pair<int, char>>> MAP)
// {
//     int R = 0, B = 0, G = 0, Y = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (MAP[i][j].second == 'R')
//                 R += MAP[i][j].first;
//             else if (MAP[i][j].second == 'B')
//                 B += MAP[i][j].first;
//             else if (MAP[i][j].second == 'G')
//                 G += MAP[i][j].first;
//             else if (MAP[i][j].second == 'Y')
//                 Y += MAP[i][j].first;
//         }
//     }
//     return (R * 7 + B * 5 + G * 3 + Y * 2);
// }
// vector<vector<pair<int, char>>> SetIngredient(int P, int R, vector<vector<pair<int, char>>> MAP, int n)
// {
//     vector<vector<pair<int, char>>> Ingre(4, vector<pair<int, char>>(4, {0, 'W'}));
//     if (R == 1)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 Ingre[i][j] = Ingredients[n][4 - 1 - j][i];
//     } //n번째 재료 90도회전
//     else if (R == 2)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 Ingre[i][j] = Ingredients[n][4 - 1 - i][4 - 1 - j];
//     } //n번째 재료 180도회전
//     else if (R == 3)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 Ingre[i][j] = Ingredients[n][j][4 - 1 - i];
//     } //n번째 재료 270도회전

//     if (P == 0)
//     { //(0,0)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i][j].first += Ingre[i][j].first;
//                 if (MAP[i][j].first < 0)
//                     MAP[i][j].first = 0;
//                 else if (MAP[i][j].first > 9)
//                     MAP[i][j].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i][j].second = Ingre[i][j].second;
//             }
//         }
//     }
//     else if (P == 1)
//     { //(0,1)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i][j + 1].first += Ingre[i][j].first;
//                 if (MAP[i][j + 1].first < 0)
//                     MAP[i][j + 1].first = 0;
//                 else if (MAP[i][j + 1].first > 9)
//                     MAP[i][j + 1].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i][j + 1].second = Ingre[i][j].second;
//             }
//         }
//     }
//     else if (P == 2)
//     { //(1,0)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i + 1][j].first += Ingre[i][j].first;
//                 if (MAP[i + 1][j].first < 0)
//                     MAP[i + 1][j].first = 0;
//                 else if (MAP[i + 1][j].first > 9)
//                     MAP[i + 1][j].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i + 1][j].second = Ingre[i][j].second;
//             }
//         }
//     }
//     else
//     { //(1,1)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i + 1][j + 1].first += Ingre[i][j].first;
//                 if (MAP[i + 1][j + 1].first < 0)
//                     MAP[i + 1][j + 1].first = 0;
//                 else if (MAP[i + 1][j + 1].first > 9)
//                     MAP[i + 1][j + 1].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i + 1][j + 1].second = Ingre[i][j].second;
//             }
//         }
//     }
//     return MAP;
// }
// int getScore(vector<vector<pair<int, char>>> MAP)
// {

//     for (int i = 0; i < 3; i++) // 3
//     {
//         MAP = SetIngredient(point[i], rotation[i], MAP, permutation[i]);
//     }

//     return Cal(MAP);
// }
// void Solve()
// {
//     do
//     {
//         do
//         {
//             do
//             {
//                 ret = max(ret, getScore(MAP));
//                 reverse(rotation.begin() + 3, rotation.end());
//             } while (next_permutation(rotation.begin(), rotation.end())); //0도 90도 180도 270도 회전
//             reverse(point.begin() + 3, point.end());
//         } while (next_permutation(point.begin(), point.end())); //(0,0) (0,1) (1,0) (1,1) 4개중 어느위치
//         reverse(permutation.begin() + 3, permutation.end());
//     } while (next_permutation(permutation.begin(), permutation.end()));

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

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// int n;
// vector<vector<vector<pair<int, char>>>> Ingredients;
// vector<int> permutation;
// vector<bool> visited;
// vector<int> point;
// vector<int> rotation;
// int ret = -1e9;
// void Init()
// {

//     cin >> n;
//     visited.resize(n, false);

//     for (int i = 0; i < n; i++)
//     {
//         vector<vector<pair<int, char>>> Ingredient(4, vector<pair<int, char>>(4));
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> Ingredient[i][j].first;

//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> Ingredient[i][j].second;

//         Ingredients.push_back(Ingredient);
//     } //입력받기
// }
// int Cal(vector<vector<pair<int, char>>> &MAP)
// {
//     vector<int> color(4, 0);
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (MAP[i][j].second == 'R')
//                 color[0] += MAP[i][j].first;
//             else if (MAP[i][j].second == 'B')
//                 color[1] += MAP[i][j].first;
//             else if (MAP[i][j].second == 'G')
//                 color[2] += MAP[i][j].first;
//             else if (MAP[i][j].second == 'Y')
//                 color[3] += MAP[i][j].first;
//         }
//     }
//     return (color[0] * 7 + color[1] * 5 + color[2] * 3 + color[3] * 2);
// }
// vector<vector<pair<int, char>>> &SetIngredient(int P, int R, vector<vector<pair<int, char>>> &MAP, int n)
// {
//     vector<vector<pair<int, char>>> Ingre(4, vector<pair<int, char>>(4, {0, 'W'}));
//     if (R == 1)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 Ingre[i][j] = Ingredients[n][4 - 1 - j][i];
//     } //n번째 재료 90도회전
//     else if (R == 2)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 Ingre[i][j] = Ingredients[n][4 - 1 - i][4 - 1 - j];
//     } //n번째 재료 180도회전
//     else if (R == 3)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 Ingre[i][j] = Ingredients[n][j][4 - 1 - i];
//     } //n번째 재료 270도회전

//     if (P == 0)
//     { //(0,0)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i][j].first += Ingre[i][j].first;
//                 if (MAP[i][j].first < 0)
//                     MAP[i][j].first = 0;
//                 else if (MAP[i][j].first > 9)
//                     MAP[i][j].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i][j].second = Ingre[i][j].second;
//             }
//         }
//     }
//     else if (P == 1)
//     { //(0,1)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i][j + 1].first += Ingre[i][j].first;
//                 if (MAP[i][j + 1].first < 0)
//                     MAP[i][j + 1].first = 0;
//                 else if (MAP[i][j + 1].first > 9)
//                     MAP[i][j + 1].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i][j + 1].second = Ingre[i][j].second;
//             }
//         }
//     }
//     else if (P == 2)
//     { //(1,0)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i + 1][j].first += Ingre[i][j].first;
//                 if (MAP[i + 1][j].first < 0)
//                     MAP[i + 1][j].first = 0;
//                 else if (MAP[i + 1][j].first > 9)
//                     MAP[i + 1][j].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i + 1][j].second = Ingre[i][j].second;
//             }
//         }
//     }
//     else
//     { //(1,1)
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 MAP[i + 1][j + 1].first += Ingre[i][j].first;
//                 if (MAP[i + 1][j + 1].first < 0)
//                     MAP[i + 1][j + 1].first = 0;
//                 else if (MAP[i + 1][j + 1].first > 9)
//                     MAP[i + 1][j + 1].first = 9;
//                 if (Ingre[i][j].second != 'W')
//                     MAP[i + 1][j + 1].second = Ingre[i][j].second;
//             }
//         }
//     }
//     return MAP;
// }
// int getScore()
// {

//     vector<vector<pair<int, char>>> MAP(5, vector<pair<int, char>>(5, {0, 'W'}));

//     for (int i = 0; i < 3; i++) // 3
//     {
//         MAP = SetIngredient(point[i], rotation[i], MAP, permutation[i]);
//     }

//     return Cal(MAP);
// }
// void dfs(int cnt)
// {
//     if (cnt == 3)
//     {
//         ret = max(ret, getScore());
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             permutation.push_back(i);
//             for (int j = 0; j < 4; j++)
//             {
//                 rotation.push_back(j);
//                 for (int k = 0; k < 4; k++)
//                 {
//                     point.push_back(k);
//                     dfs(cnt + 1);
//                     point.pop_back();
//                 }
//                 rotation.pop_back();
//             }
//             permutation.pop_back();
//             visited[i] = false;
//         }
//     }
// }
// void Solve()
// {
//     dfs(0);
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