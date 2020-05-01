#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[200];
vector<bool> visited;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (computers[i][j] == 1)
            {
                adjlist[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            //bfs 돌리면됨
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int h = q.front();
                q.pop();

                for (int j = 0; j < adjlist[h].size(); j++)
                {
                    if (!visited[adjlist[h][j]])
                    {
                        q.push(adjlist[h][j]);
                        visited[adjlist[h][j]] = true;
                    }
                }
            }
        }
    }

    return answer;
}

// for(int i=0; i<n; i++){
//     cout<<i<<" : ";
//     for(int j=0; j<adjlist[i].size(); j++){
//         cout<<adjlist[i][j]<<"-> ";
//     }
//     cout<<endl;
// }