#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<vector<int>> adjlist;
vector<int> indegree;
vector<int> buildingTime;
vector<int> result;
void Init(){
    cin>>n;
    adjlist.resize(n+1);
    indegree.resize(n+1);
    buildingTime.resize(n+1);
    result.resize(n+1);
    for(int i=1; i<=n; i++){
        cin>>buildingTime[i];
        int prev;
        int cnt=0;
        while(cin>>prev){
            if(prev==-1)break;
            adjlist[prev].push_back(i);
            cnt++;
        }
        indegree[i]=cnt;
    }
}
void Solve(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
            result[i]=buildingTime[i];
        }
    }

    for(int i=1; i<=n; i++){
        if(q.empty())break;

        int cur=q.front();
        q.pop();

        for(auto next: adjlist[cur]){
            result[next]=max(result[next],result[cur]+buildingTime[next]);
            if(--indegree[next]==0)q.push(next);
        }
    }

    for(int i=1; i<=n; i++)    
        cout<<result[i]<<endl;
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