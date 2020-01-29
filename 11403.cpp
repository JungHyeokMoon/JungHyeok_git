#include <bits/stdc++.h>
using namespace std;
int n;


vector<int> adjlist[100];
bool isvisited[100][100];

void Input(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            int num;
            cin>>num;
            if(num==1){
                adjlist[i].push_back(j);
            }
        }
    }
    
}
void Output(){
    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cout<<isvisited[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void dfs(int a, int b){
    isvisited[a][b]=true;
    //cout<<"true : "<<a<<" , "<<b<<"\n";
    int len=adjlist[b].size();
    for(int k=0; k<len ; k++){
        int nextvertex=adjlist[b][k];
        if(!isvisited[a][nextvertex]){
            //cout<<"a :"<<a<<" , "<<"nextvertex : "<<nextvertex<<"\n";
            dfs(a,nextvertex);
        }
    }
}
void Solve(){
    for(int i=0; i<n; i++){
        int len=adjlist[i].size();
        for(int j=0; j<len ; j++){
            dfs(i,adjlist[i][j]);
        }
    }
    Output();    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}