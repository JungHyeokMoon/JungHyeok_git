// #include <bits/stdc++.h>
// using namespace std;
// const int MAX=100001;
// int N,K;

// bool isinside(int hc){
//     if(hc<0 || hc>100000)return false;
//     return true;
// }
// bool visited[MAX];
// int parent[MAX];
// vector<int >ret;
// void print(int hc){
//     if(parent[hc]==-1)return ;
//     ret.push_back(parent[hc]);
//     print(parent[hc]);
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     fill(parent,parent+MAX,-1);
//     cin>>N>>K;

//     visited[N]=true;
//     queue<pair<int,int>>q;
//     q.push({N,0});

//     while(!q.empty()){
//         int hc=q.front().first;
//         int ht=q.front().second;

//         q.pop();
//         if(hc==K){
//             cout<<ht<<"\n";

//             ret.push_back(hc);

//             print(hc);
//             reverse(ret.begin(),ret.end());
//             for(auto i : ret)cout<<i<<" ";
//             return 0;
//         }
//         int nc=hc*2;
//         if(isinside(nc)&&!visited[nc]){
//             visited[nc]=true;
//             q.push({nc,ht+1});
//             parent[nc]=hc;
//         }

//         nc=hc-1;
//         if(isinside(nc)&&!visited[nc]){
//             visited[nc]=true;
//             q.push({nc,ht+1});
//             parent[nc]=hc;
//         }

//         nc=hc+1;
//         if(isinside(nc)&&!visited[nc]){
//             visited[nc]=true;
//             q.push({nc,ht+1});
//             parent[nc]=hc;
//         }
//     }

//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, k;
vector<int> dist;
vector<int> parent;
const int MAX = 100000;
void Init()
{
    cin >> n >> k;
    dist.resize(MAX + 1, -1);
    parent.resize(MAX + 1, -1);
}

int retNc(int hc, int idx)
{
    if (idx == 0)
        return 2 * hc;
    else if (idx == 1)
        return hc - 1;
    else
        return hc + 1;
}
bool isInside(int c)
{
    if (c >= 0 && c <= MAX)
        return true;
    return false;
}
void Ouput(int hc)
{
    vector<int> ret;
    int temp = hc;
    // cout << hc << " ";
    ret.push_back(temp);
    while (temp != n)
    {
        // cout << parent[temp] << " ";
        ret.push_back(parent[temp]);
        temp = parent[temp];
    }
    for (int i = ret.size() - 1; i >= 0; i--)
    {
        cout << ret[i] << " ";
    }
    // int temp = n;
    // while (temp != k)
    // {
    //     cout << temp << " ";
    //     temp = parent[temp];
    // }
}
void Solve()
{
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int hc = q.front();
        q.pop();
        if (hc == k)
        {
            cout << dist[hc] << endl;
            //경로출력
            Ouput(hc);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            int nc = retNc(hc, i);
            if (!isInside(nc))
                continue;
            if (dist[nc] >= 0)
                continue;
            q.push(nc);
            dist[nc] = dist[hc] + 1;
            parent[nc] = hc;
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