#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;

vector<char> kind;
vector<long long> result;
vector<vector<int>> adjlist;
void Init()
{
    cin >> n;
    kind.resize(n+1);
    result.resize(n + 1, 0);
    adjlist.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int start;
        cin>>kind[i]>>result[i]>>start;
        adjlist[start].push_back(i);
    }
}
long long CalcSheep(int cur){
    long long sum=0;
    for(auto next: adjlist[cur])
        sum+=CalcSheep(next);
    
    if(kind[cur]=='S') return sum+=result[cur];
    else return sum-result[cur]>0 ? sum-result[cur] : 0 ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    cout<<CalcSheep(1)<<endl;
    return 0;
}