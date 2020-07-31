#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<vector<pair<int, char>>>> Ingredients;
// vector<bool> combi;
vector<int> permutation;
vector<int> point;
vector<int> rotation;
int ret = -1e9;
void Output(vector<vector<pair<int, char>>> &MAP)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << MAP[i][j].first << MAP[i][j].second << " ";
        }
        cout << endl;
    }
}
void Init()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        permutation.push_back(i);
    for (int i = 0; i < 12; i++)
    {
        point.push_back(i % 4);
        rotation.push_back(i % 4);
    }
    sort(point.begin(), point.end());
    sort(rotation.begin(), rotation.end());

    for (int i = 0; i < n; i++)
    {
        vector<vector<pair<int, char>>> Ingredient(4, vector<pair<int, char>>(4));
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> Ingredient[i][j].first;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> Ingredient[i][j].second;

        Ingredients.push_back(Ingredient);
    }
}
int Cal(vector<vector<pair<int, char>>> &MAP)
{
    vector<int> color(4, 0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (MAP[i][j].second == 'R')
                color[0] += MAP[i][j].first;
            else if (MAP[i][j].second == 'B')
                color[1] += MAP[i][j].first;
            else if (MAP[i][j].second == 'G')
                color[2] += MAP[i][j].first;
            else if (MAP[i][j].second == 'Y')
                color[3] += MAP[i][j].first;
        }
    }
    return (color[0] * 7 + color[1] * 5 + color[2] * 3 + color[3] * 2);
}
void SetIngredient(int P, int R, vector<vector<pair<int, char>>> &MAP, int n)
{
    vector<vector<pair<int, char>>> Ingre(4, vector<pair<int, char>>(4, {0, 'W'}));
    if (R == 1)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                Ingre[i][j] = Ingredients[n][4 - 1 - j][i];
    } //n번째 재료 90도회전
    else if (R == 2)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                Ingre[i][j] = Ingredients[n][4 - 1 - i][4 - 1 - j];
    } //n번째 재료 180도회전
    else if (R == 3)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                Ingre[i][j] = Ingredients[n][j][4 - 1 - i];
    } //n번째 재료 270도회전

    if (P == 0)
    { //(0,0)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MAP[i][j].first += Ingre[i][j].first;
                if (MAP[i][j].first < 0)
                    MAP[i][j].first = 0;
                else if (MAP[i][j].first > 9)
                    MAP[i][j].first = 9;
                if (Ingre[i][j].second != 'W')
                    MAP[i][j].second = Ingre[i][j].second;
            }
        }
    }
    else if (P == 1)
    { //(0,1)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MAP[i][j + 1].first += Ingre[i][j].first;
                if (MAP[i][j + 1].first < 0)
                    MAP[i][j + 1].first = 0;
                else if (MAP[i][j + 1].first > 9)
                    MAP[i][j + 1].first = 9;
                if (Ingre[i][j].second != 'W')
                    MAP[i][j + 1].second = Ingre[i][j].second;
            }
        }
    }
    else if (P == 2)
    { //(1,0)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MAP[i + 1][j].first += Ingre[i][j].first;
                if (MAP[i + 1][j].first < 0)
                    MAP[i + 1][j].first = 0;
                else if (MAP[i + 1][j].first > 9)
                    MAP[i + 1][j].first = 9;
                if (Ingre[i][j].second != 'W')
                    MAP[i + 1][j].second = Ingre[i][j].second;
            }
        }
    }
    else
    { //(1,1)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MAP[i + 1][j + 1].first += Ingre[i][j].first;
                if (MAP[i + 1][j + 1].first < 0)
                    MAP[i + 1][j + 1].first = 0;
                else if (MAP[i + 1][j + 1].first > 9)
                    MAP[i + 1][j + 1].first = 9;
                if (Ingre[i][j].second != 'W')
                    MAP[i + 1][j + 1].second = Ingre[i][j].second;
            }
        }
    }
}
int getScore()
{

    vector<vector<pair<int, char>>> MAP(5, vector<pair<int, char>>(5, {0, 'W'}));
    vector<int> idx;
    for (int i = 0; i < 3; i++)
        idx.push_back(permutation[i]); //조합고르기

    for (int i = 0; i < idx.size(); i++) // 3
    {
        SetIngredient(point[i], rotation[i], MAP, idx[i]);
    }

    return Cal(MAP);
}
void Solve()
{
    int cnt = 0;
    // do
    // {
    do
    {
        do
        {
            do
            {
                ret = max(ret, getScore());
                reverse(rotation.begin() + 3, rotation.end());
            } while (next_permutation(rotation.begin(), rotation.end())); //0도 90도 180도 270도 회전
            reverse(point.begin() + 3, point.end());
        } while (next_permutation(point.begin(), point.end())); //(0,0) (0,1) (1,0) (1,1) 4개중 어느위치
        reverse(permutation.begin() + 3, permutation.end());
    } while (next_permutation(permutation.begin(), permutation.end()));
    // } while (next_permutation(combi.begin(), combi.end()));     // n개중에 3개를 고르는 조합
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