#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist;
const int INF=1000000000;
void Floyd(int n,int & answer){
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(dist[i][j]!=INF || dist[j][i]!=INF)cnt++; //확정할수 있는 승/패가 n-1 이면 등수확정이 가능함
        }
        if(cnt==n-1)answer++;
    }
}
void Print(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==INF) cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    dist.resize(n+1,vector<int>(n+1,INF));
    for(auto i : results)
        dist[i[0]][i[1]]=1;
    Floyd(n,answer);
    // Print(n);
    
    return answer;
}

int main(){
    cout<<solution(5,{{4,3},{4,2},{3,2},{1,2},{2,5}})<<endl;
    return 0;
}