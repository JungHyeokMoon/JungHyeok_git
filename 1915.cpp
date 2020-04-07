#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
vector<vector<int>> Rec;
int result = 0;
void Input()
{
    cin >> n >> m;
    Rec.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            Rec[i][j] = temp[j] - '0';
        }
    }
}

void Solve()
{
    if (n == 1 || m == 1)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j< m; j++){
                if(Rec[i][j]==1){
                    cout<<1<<endl;
                    return ;
                }
            }
        }
        cout<<0<<endl;
        return;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (Rec[i][j] == 1)
                {
                    Rec[i][j] = min(min(Rec[i - 1][j - 1], Rec[i - 1][j]), Rec[i][j - 1]) + 1;
                    result = max(result, Rec[i][j]);
                }
            }
        }
        cout << result * result << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}