#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, r, m, k;
vector<int> route;
map<string, int> city;
const int INF = 1000000000;
vector<vector<int>> withOutTicketDist;
vector<vector<int>> withTicketDist;
void Init()
{
    cin >> n >> r;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        city[temp] = cnt++;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        route.push_back(city[temp]);
    }

    withOutTicketDist.resize(n, vector<int>(n, INF));
    withTicketDist.resize(n, vector<int>(n, INF));
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string way, start, destination;
        int cost;
        cin >> way >> start >> destination >> cost;
        if (withOutTicketDist[city[start]][city[destination]] > cost)
        {
            withOutTicketDist[city[start]][city[destination]] = cost;
            withOutTicketDist[city[destination]][city[start]] = cost;
        }
        if (way == "Mugunghwa" || way == "ITX-Saemaeul" || way == "ITX-Cheongchun")
        {
            withTicketDist[city[start]][city[destination]] =0;
            withTicketDist[city[destination]][city[start]] =0;
        }
        else if(way=="S-Train"|| way=="V-Train"){
            if(withTicketDist[city[start]][city[destination]]>cost/2){
                withTicketDist[city[start]][city[destination]]=cost/2;
                withTicketDist[city[destination]][city[start]]=cost/2;
            }
        }else{
            if(withTicketDist[city[start]][city[destination]]>cost){
                withTicketDist[city[start]][city[destination]]=cost;
                withTicketDist[city[destination]][city[start]]=cost;
            }
        }
    }

}
long long Floyd(vector<vector<int>> & dist)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    long long ret=0;
    for (int i = 0; i < m - 1; i++)
        ret += dist[route[i]][route[i + 1]];
    return ret;
}
void Solve()
{
    long long withOut = Floyd(withOutTicketDist);
    long long withTicket = Floyd(withTicketDist);

    if(withTicket+r<withOut)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
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