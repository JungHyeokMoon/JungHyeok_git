// #include <bits/stdc++.h>
// using namespace std;
// const int MAX=100001;
// int N,K;

// bool isinside(int hc){
//     if(hc<0 || hc>100000)return false;
//     return true;
// }
// bool visited[MAX];

// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>N>>K;
//     queue<pair<int,int>> q;
//     q.push({N,0});
//     visited[N]=true;

//     while(!q.empty()){
//         int hc=q.front().first;
//         int ht=q.front().second;
//         q.pop();

//         //cout<<"hc : "<<hc<<" , "<<"ht : "<<ht<<"\n";

//         if(hc==K){
//             cout<<ht<<"\n";
//             return 0;
//         }

//         int nc=hc*2;
//         if(isinside(nc)&&!visited[nc]){
//             q.push({nc,ht});
//             visited[nc]=true;
//         }

//         nc=hc-1;
//         if(isinside(nc)&&!visited[nc]){
//             q.push({nc,ht+1});
//             visited[nc]=true;
//         }

//         nc=hc+1;
//         if(isinside(nc)&&!visited[nc]){
//             q.push({nc,ht+1});
//             visited[nc]=true;
//         }

//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, k;
vector<int> visited;
const int MAX = 100000;
void Init()
{
    cin >> n >> k;
    visited.resize(MAX + 1, false);
}
bool IsInside(int c)
{
    if (c >= 0 && c <= MAX)
        return true;
    return false;
}
int nextCoordi(int hc, int idx)
{
    if (idx == 0)
        return 2 * hc;
    else if (idx == 1)
        return hc + 1;
    else
        return hc - 1;
}
void Solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({-0, n});
    visited[n] = true;
    while (!pq.empty())
    {
        int ht = pq.top().first;
        int hc = pq.top().second;
        pq.pop();
        if (hc == k)
        {
            cout << ht << endl;
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            int nc = nextCoordi(hc, i);
            if (!IsInside(nc))
                continue;
            if (visited[nc] == true)
                continue;
            if (i == 0)
            {
                pq.push({ht, nc});
                visited[nc] = true;
            }
            else
            {
                pq.push({(ht + 1), nc});
                visited[nc] = true;
            }
        }
    }
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
//간선의 가중치가 다를경우 bfs 를 적용할수 없기때문에 다익스트라를 위해서 우선순위큐를 사용