// #include <bits/stdc++.h>
// using namespace std;
// int n;


// vector<int> adjlist[100];
// bool isvisited[100][100];

// void Input(){
//     cin>>n;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n ; j++){
//             int num;
//             cin>>num;
//             if(num==1){
//                 adjlist[i].push_back(j);
//             }
//         }
//     }
    
// }
// void Output(){
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<n ; j++){
//             cout<<isvisited[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
// void dfs(int a, int b){
//     isvisited[a][b]=true;
//     //cout<<"true : "<<a<<" , "<<b<<"\n";
//     int len=adjlist[b].size();
//     for(int k=0; k<len ; k++){
//         int nextvertex=adjlist[b][k];
//         if(!isvisited[a][nextvertex]){
//             //cout<<"a :"<<a<<" , "<<"nextvertex : "<<nextvertex<<"\n";
//             dfs(a,nextvertex);
//         }
//     }
// }
// void Solve(){
//     for(int i=0; i<n; i++){
//         int len=adjlist[i].size();
//         for(int j=0; j<len ; j++){
//             dfs(i,adjlist[i][j]);
//         }
//     }
//     Output();    
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     Input();
//     Solve();
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> dist;
const int INF=1000000000;
void Init(){
    cin>>n;
    dist.resize(n,vector<int>(n));
    for(auto & i : dist){
        for(auto & j :i){
            cin>>j;
            j=(j==0)? INF:j;
        }
    }

    
}
void Print(){
    for(auto & i :dist){
        for(auto & j :i){
            if(j==INF) cout<<0<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
    }
}
void Solve(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    Print();
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