#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
typedef struct planet
{
    int idx;
    int x, y, z;
} planet;
vector<planet> v;
// planet v[100000];
vector<int> parent;
// int parent[100000];
void Init()
{
    cin >> n;
    v.resize(n);
    parent.resize(n);
    for(int i=0; i<n; i++){
        v[i].idx=i;
        cin>>v[i].x>>v[i].y>>v[i].z;
        parent[i]=i;
    }
    
}
bool CompareX(planet &a, planet &b){
    return a.x<b.x;
}
bool CompareY(planet &a, planet &b){
    return a.y<b.y;
}
bool CompareZ(planet &a, planet &b){
    return a.z<b.z;
}
typedef struct edge{
    int cost, u ,v;

    bool operator<(const edge & e){
        return cost<e.cost;
    } //등호붙일경우 런타임에러가 난다. 
}edge;
vector<edge> e;

int Find(int u){
    if(u==parent[u]) return u;
    else return parent[u]=Find(parent[u]);
}
void Merge(int u, int v){
    u=Find(u);
    v=Find(v);

    parent[v]=u;
}
void Solve()
{
    
    sort(v.begin(),v.end(),CompareX);
    for(int i=0; i<n-1; i++)
        e.push_back({abs(v[i].x-v[i+1].x),v[i].idx,v[i+1].idx});

    sort(v.begin(),v.end(),CompareY);
    for(int i=0; i<n-1; i++)
        e.push_back({abs(v[i].y-v[i+1].y),v[i].idx,v[i+1].idx});

    sort(v.begin(),v.end(),CompareZ);
    for(int i=0; i<n-1; i++)
        e.push_back({abs(v[i].z-v[i+1].z),v[i].idx,v[i+1].idx});

    sort(e.begin(),e.end());

    int cnt=0;
    int ret=0;
    for(auto i :e){
        if(Find(i.u)!=Find(i.v)){
            cnt++;
            Merge(i.u,i.v);
            ret+=i.cost;
        }
        if(cnt==n-1)break;
    }
    cout<<ret<<endl;
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