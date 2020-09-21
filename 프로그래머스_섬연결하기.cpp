#include <bits/stdc++.h>
using namespace std;
bool Compare(vector<int> &a, vector<int> &b)
{
    return a.back() < b.back() ? true : false;
}
vector<int> parent;
void Init(int n, vector<vector<int>> &costs)
{
    int cnt = 0;
    parent.resize(n);
    for(int i=0; i<n; i++)
        parent[i]=i;
    sort(costs.begin(), costs.end(), Compare);
    
}
int Find(int u)
{
    if (u == parent[u])
        return u;
    else
        return parent[u] = Find(parent[u]);
}
void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    parent[v] = u;
}
int solution(int n, vector<vector<int>> costs)
{
    Init(n, costs);
    vector<pair<int, int>> edge;
    int answer = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if(edge.size()==n-1)
            break;
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];

        if (Find(start) != Find(end))
        { //싸이클이 아닐경우
            edge.push_back({start, end});
            answer += cost;
            Union(start, end);
        }
        
    }
    return answer;
}

int main()
{
    cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}});
    // cout<<solution(4,{{0,1,1},{0,2,2},{2,3,1}});
    // cout<<solution(5,{{0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4},{2,4,6},{4,0,7}});
    // cout<<solution(5,{{0,1,1},{3,1,1},{0,2,2},{0,3,2},{0,4,100}});
    // cout<<solution(6,{{0,1,5},{0,3,2},{0,4,3},{1,4,1},{3,4,10},{1,2,2},{2,5,3},{4,5,4}});
    // cout<<solution(4,{{0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4}});
    // cout<<solution(5,{{0,1,1},{0,2,2},{1,2,5},{1,3,3},{2,3,8},{3,4,1}});
    // cout<<solution(5,{{0,1,1},{3,4,1},{1,2,2},{2,3,4}});
    // cout<<solution(4,{{2,3,3},{2,4,4},{3,4,7},{3,5,3},{4,5,10}});
    return 0;
}