#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
vector<vector<int>> adjlist;
vector<pair<int, int>> answer; //first : 수 , second: 번호
void Input()
{
    cin >> n >> m;
    adjlist.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node i : " << i;
    //     for (int j = 0; j < adjlist[i].size(); j++)
    //     {
    //         cout << " " << adjlist[i][j] << "-> ";
    //     }
    //     cout << endl;
    // }
}
int bfs(int Node)
{
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    visited[Node] = true;
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({Node, 0});
    while (!q.empty())
    {
        int hNode = q.front().first;
        int hstep = q.front().second;
        cnt += hstep;
        // cout << "hstep : " << hstep << " , cnt : " << cnt << endl;
        q.pop();

        int length = adjlist[hNode].size();
        for (int i = 0; i < length; i++)
        {
            int nextNode = adjlist[hNode][i];
            int nextstep = hstep + 1;
            // cout << "NextNode : " << nextNode << "Nextstep : " << nextstep << endl;
            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                q.push({nextNode, nextstep});
            }
        }
       
    }
    
    return cnt;
}
void Solve(){
    for(int i=1; i<=n; i++){
        int count=bfs(i);
        answer.push_back({count,i});
    }
    sort(answer.begin(),answer.end());
    cout<<answer[0].second<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}