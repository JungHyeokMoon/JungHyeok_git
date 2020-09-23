#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m;
vector<vector<char>> quento;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<bool>> visited(3, vector<bool>(3, false));
vector<pair<int, int>> coordi;
vector<char> keyboard;
bool Isinside(int y, int x)
{
    if (y >= 0 && y < 3 && x >= 0 && x < 3)
        return true;
    return false;
}
void Init()
{
    cin >> n >> m;
    quento.resize(3, vector<char>(3));
    for (int i = 0; i < 3; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 3; j++)
        {
            quento[i][j] = temp[j];
        }
    }
}
bool dfs(int y, int x)
{
    if (keyboard.size() == 2 * m - 1)
    {
        vector<int> number;
        vector<char> op;
        for (int i = 0; i < keyboard.size(); i++)
        {
            if (0 <= keyboard[i] - '0' && keyboard[i] - '0' <= 9)
                number.push_back(keyboard[i] - '0');
            else
                op.push_back(keyboard[i]);
        }

        // for (auto i : coordi)
        //     cout << i.first << " " << i.second << endl;
        // cout << "---------------------" << endl;
        // for (auto i : number)
        //     cout << i << " ";
        // cout << "---------------------" << endl;
        // for (auto i : op)
        //     cout << i << " ";
        // cout << "---------------------" << endl;
        //계산결과가 맞으면
        int calc = 0;
        if (op[0] == '+')
            calc = number[0] + number[1];
        else if (op[0] == '-')
            calc = number[0] - number[1];
        else
            calc = number[0] / number[1];

        for (int i = 1; i < op.size(); i++)
        {
            if (op[i] == '+')
                calc += number[i + 1];
            else if (op[i] == '-')
                calc -= number[i + 1];
            else
                calc /= number[i + 1];
        }

        if (calc == n)
        {
            cout<<1<<endl;
            for (auto i : coordi)
                cout << i.first << " " << i.second << endl;
            return true;
        }
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i].first;
        int nx = x + dir[i].second;
        if (!Isinside(ny, nx))
            continue;
        if (visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        coordi.push_back({ny, nx});
        keyboard.push_back(quento[ny][nx]);
        if (dfs(ny, nx))
            return true;
        visited[ny][nx] = false;
        coordi.pop_back();
        keyboard.pop_back();
    }

    return false;
}
void Solve()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (0 <= quento[i][j] - '0' && quento[i][j] - '0' <= 9)
            {
                visited[i][j] = true;
                coordi.push_back({i, j});
                keyboard.push_back(quento[i][j]);
                if (dfs(i, j))
                    return;
                visited[i][j] = false;
                coordi.pop_back();
                keyboard.pop_back();
            }
        }
    }
    cout << 0 << endl;
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