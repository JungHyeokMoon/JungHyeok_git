#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n,k,f;
vector<vector<int>> adjlist;
vector<vector<bool>> isFriend;
vector<int> friendNum;
vector<int>ret;
vector<bool> visited;
void testOutput(){
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n; j++){
            cout<<isFriend[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<i<<" : ";
        for(int j=0; j<adjlist[i].size(); j++){
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=1; i<=n ; i++){
        cout<<friendNum[i]<<endl;
    }
    cout<<endl;
}
void Output(){
    // cout<<"ret size : "<<ret.size()<<endl;
    sort(ret.begin(),ret.end());
    for(int i=0; i<k; i++){
        cout<<ret[i]<<endl;
    }
    return ;
}
void Input(){
    cin>>k>>n>>f;
    adjlist.resize(n+1);
    isFriend.resize(n+1,vector<bool>(n+1,false));
    friendNum.resize(n+1,0);
    visited.resize(n+1,false);
    for(int i=0; i<f; i++){
        int a,b;
        cin>>a>>b;
        isFriend[a][b]=true;
        isFriend[b][a]=true;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        friendNum[a]++;
        friendNum[b]++;
    }
    for(int i=1; i<=n ; i++){
        sort(adjlist[i].begin(),adjlist[i].end());
    }
    // testOutput();
}
void backTracking(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int h=q.front();
        // cout<<"h : "<<h<<endl;
        q.pop();
        for(int i=0; i<adjlist[h].size(); i++){
            int nf=adjlist[h][i];
            if(visited[nf])continue;
            // cout<<"nf : "<<nf<<endl;
            bool flag=true;
            for(int j=0; j<ret.size(); j++){
                if(!isFriend[nf][ret[j]]){
                    flag=false;
                    break;
                }
            }
            if(flag==false)continue;
            ret.push_back(nf);
            q.push(nf);
            visited[nf]=true;
        }
    }
    // cout<<"ret output"<<endl;
    // Output();
    
}

void Solve(){
    for(int i=1; i<=n ; i++){
        if(friendNum[i]<k-1)continue;
        ret.clear();
        fill(visited.begin(),visited.begin()+n+1,false);
        visited[i]=true;
        ret.push_back(i);
        backTracking(i);
        if(ret.size()>=k){
            Output();
            return ;
        }
        ret.pop_back();
        visited[i]=false;
        
    }
    cout<<-1<<endl;
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Input();
    Solve();
    return 0;
}