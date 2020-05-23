#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, k;
vector<pair<int, int>> candidate;
// queue<pair<int, int>> q;
vector<int> recomend;
void Input()
{
    cin >> n >> k;
    // candidate.resize(n, {0, 0});
    recomend.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> recomend[i];
    }
}

void Output()
{
    sort(candidate.begin(), candidate.end());
    for (vector<pair<int, int>>::iterator it = candidate.begin(); it != candidate.end(); it++)
    {
        cout << (*it).first << " ";
    }
    cout << endl;
}
void Solve()
{
    for (int i = 0; i < k; i++)
    {
        int Temp = recomend[i];
        bool flag = false;
        int lowestCandidateIndex;
        int lowestRecommend = 1e9;
        for (vector<pair<int, int>>::iterator it = candidate.begin(); it != candidate.end(); it++)
        {
            if ((*it).first == recomend[i])
            {
                (*it).second++;
                flag = true;
                break;
            }
            if (lowestRecommend > (*it).second)
            {
                lowestRecommend = (*it).second;
                lowestCandidateIndex = it - candidate.begin();
            }
        }

        if (!flag)
        { //못찾았으면
            if (candidate.size() == n)
            {
                candidate.erase(candidate.begin() + lowestCandidateIndex);
                candidate.push_back({Temp, 1});
            } //가득찬경우
            else
            {
                candidate.push_back({Temp, 1});
            }
        }
    }
    Output();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    // vector<int>::iterator it;
    // for (it = recomend.begin(); it != recomend.end(); it++)
    // {
    //     if ((*it) == 6)
    //     {
    //         break;
    //     }
    // }
    // cout << it - recomend.begin();
    return 0;
}