#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int A[101][101];
int ret = 0;
int numbercount[101];
void Input()
{
    cin >> r >> c >> k;
    r = r;
    c = c;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> A[i][j];
        }
    }
}

// void output(){
//     for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             cout<<A[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     return ;
// }
int R_operation(int row, int col)
{
    vector<int> Size;
    for (int i = 1; i <= row; i++)
    {
        vector<pair<int, int>> V;
        memset(numbercount, 0, sizeof(numbercount));
        for (int j = 1; j <= col; j++)
        {
            numbercount[A[i][j]]++;
        }
        for (int j = 1; j < 101; j++)
        {
            if (numbercount[j] == 0)
                continue;
            V.push_back({numbercount[j], j});
        } //이렇게넣어야지 정렬할때 쉬움 ,앞의 데이터를 오름차순정렬 , 같다면 두번째 데이터기준으로 오름차순
        sort(V.begin(), V.end());
        for (int j = 1; j <= col; j++)
        {
            A[i][j] = 0;
        } //정렬전에 더 길수가 있기때문에
        int Idx = 1;
        for (int j = 0; j < V.size(); j++)
        {
            A[i][Idx++] = V[j].second;
            A[i][Idx++] = V[j].first;
        }
        Idx--;
        Size.push_back(Idx);
    }
    sort(Size.begin(), Size.end());
    return Size.back();
}
int C_operation(int row, int col)
{
    vector<int> Size;
    for (int i = 1; i <= col; i++)
    {
        memset(numbercount, 0, sizeof(numbercount));
        vector<pair<int, int>> V;
        for (int j = 1; j <= row; j++)
        {
            numbercount[A[j][i]]++;
        }
        for (int j = 1; j < 101; j++)
        {
            if (numbercount[j] == 0)
                continue;
            V.push_back({numbercount[j], j});
        }
        sort(V.begin(), V.end());
        for (int j = 1; j <= row; j++)
        {
            A[j][i] = 0;
        }
        int Idx = 1;
        for (int j = 0; j < V.size(); j++)
        {
            A[Idx++][i] = V[j].second;
            A[Idx++][i] = V[j].first;
        }
        Idx--;
        Size.push_back(Idx);
    }
    sort(Size.begin(), Size.end());
    return Size.back();
}
void Solve()
{
    int row = 3;
    int col = 3;
    // 처음은 행이나 열이나 똑같이 길이가 3임
    while (1)
    {
        if (ret > 100)
        {
            cout << -1 << "\n";
            return;
        } //100넘어가면 -1출력후 return
        if (A[r][c] == k)
        {
            cout << ret << "\n";
            return;
        } //k가되면 답출력후 return
        if (row >= col)
        {
            col = R_operation(row, col);

        } //행의갯수 >=열의갯수
        else
        {
            row = C_operation(row, col);
        } //행의갯수<열의갯수
        ret++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
}