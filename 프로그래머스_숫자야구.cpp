#include <bits/stdc++.h>
using namespace std;

int Solve(vector<vector<int>> &baseball)
{
    int ret = 0;
    for (int i = 123; i <= 987; i++)
    {
        string tmp = to_string(i);
        if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2])
            continue;
        if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            continue;

        bool flag = true;
        for (int i = 0; i < baseball.size(); i++)
        {
            string tmp2 = to_string(baseball[i][0]);
            int strike = 0;
            int ball = 0;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == k && tmp[j] == tmp2[k])
                    {
                        strike++;
                        continue;
                    }
                    if (j != k && tmp[j] == tmp2[k])
                    {
                        ball++;
                    }
                }
            }
            if (strike != baseball[i][1] || ball != baseball[i][2])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ret++;
        }
    }
    return ret;
}
int solution(vector<vector<int>> baseball)
{
    int answer = Solve(baseball);
    return answer;
}
//[[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]	2