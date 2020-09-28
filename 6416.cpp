#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void Print(int k, bool flag)
{
    if (flag)
        cout << "Case " << k << " is a tree.";
    else
        cout << "Case " << k << " is not a tree.";
    cout << endl;
}
void dfs(int cur, map<int, bool> &visited, map<int, vector<int>> &edges,int &node, int &edge)
{
    visited[cur] = true;
    node++;
    for(auto next: edges[cur]){
        if(!visited[next]){
            edge++;
            dfs(next,visited,edges,node,edge);
        }
    }
}
void Solve()
{
    int k = 0;
    while (++k)
    {
        map<int, int> indegree;
        map<int, vector<int>> edges; //시작점, 도착점
        map<int, bool> visited;
        int n = 0;
        int a, b;
        while (cin >> a >> b)
        {
            if (a == 0 && b == 0)
                break;
            else if (a < 0 && b < 0)
                return;
            edges[a].push_back(b);
            indegree[b]++;
            visited[a] = false;
            visited[b] = false;
        }

        int root=-1;
        int numberOfEdge=0;
        int numberOfNode=visited.size();
        for (auto i : edges)
        {
            if (indegree.find(i.first) == indegree.end())
                root = i.first;
            numberOfEdge+=edges[i.first].size();
        }
        if(numberOfNode==0){
            Print(k,true);
            continue;
        }
        int node=0;
        int edge=0;
        dfs(root,visited,edges,node,edge);
        if(node==numberOfNode && edge==numberOfEdge)
            Print(k,true);
        else
            Print(k,false);

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}