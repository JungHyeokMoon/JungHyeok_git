#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int row = triangle.size();
    dp.resize(row);
    for (int i = 0; i < row; i++)
        dp[i].resize(triangle[i].size(), -1);
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < row; i++)
    {
        int length = dp[i].size();
        for (int j = 0; j < length; j++)
        {
            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            if(j<dp[i-1].size())
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
        }
    }

    for (int i = 0; i < dp[row - 1].size(); i++)
        answer = max(answer, dp[row - 1][i]);
    return answer;
}

int main()
{
    cout << solution({ {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
    return 0;
}