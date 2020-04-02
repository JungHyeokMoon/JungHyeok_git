#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int s;
#define MAX 2000
bool visited[MAX][MAX]={false};//화면에 이모티콘갯수,클립보드의 이모티콘갯수
void Solve(){
    cin>>s;
    queue<pair<pair<int,int>,int>> q; //현재이모티콘갯수,클립보드의 이모티콘갯수
    q.push({{1,0},0});
    visited[1][0]=true;

    while(!q.empty()){
        int screen=q.front().first.first;
        int clipboard=q.front().first.second;
        int time=q.front().second;
        q.pop();
        if(screen==s){
            cout<<time<<endl;
            return ;
        }
        if((screen>0 && screen<MAX) && screen>=1 && !visited[screen][screen] ){
            q.push({{screen,screen},time+1});
            visited[screen][screen]=true;
        }
        if((clipboard+screen<MAX) && clipboard>=1 && !visited[screen+clipboard][clipboard] ){
            q.push({{screen+clipboard,clipboard},time+1});
            visited[screen+clipboard][clipboard]=true;
        }
        if((screen>0 && screen<MAX) && screen>=1 && !visited[screen-1][clipboard]){
            q.push({{screen-1,clipboard},time+1});
            visited[screen-1][clipboard]=true;
        }


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