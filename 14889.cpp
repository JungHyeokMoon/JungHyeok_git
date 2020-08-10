// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int arr[21][21];
// int ret=987654321;
// bool isvisited[21];
// void dfs(int playernum,int cnt){
//     if(cnt==n/2){
//         vector<int>start,link;

//         for(int i=1; i<=n ; i++){
//             if(isvisited[i])start.push_back(i);
//             else link.push_back(i);
//         }
//         int len=start.size();
//         int start_stat=0;
//         int link_stat=0;
//         for(int i=0; i<len ; i++){
//             for(int j=i+1; j<len ; j++){
//                 int start_x=start[i];
//                 int start_y=start[j];
//                 int link_x=link[i];
//                 int link_y=link[j];
//                 start_stat+=arr[start_x][start_y]+arr[start_y][start_x];
//                 link_stat+=arr[link_x][link_y]+arr[link_y][link_x];
//             }
//         }

//         ret=min(ret,abs(start_stat-link_stat));

//         return ;
//     }
//     for(int i=playernum; i<=n; i++){
//         if(!isvisited[i]){
//             isvisited[i]=true;
//             dfs(i,cnt+1);
//             isvisited[i]=false;
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);

//     cin>>n;
//     for(int i=1; i<=n ;i++){
//         for(int j=1; j<=n ; j++){
//             cin>>arr[i][j];
//         }
//     }
//     dfs(1,0);
//     cout<<ret<<"\n";
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<vector<int>> Score;
vector<bool> combi;
int ret=1e9;
void Init() {
    cin>>n;
    Score.resize(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>Score[i][j];
    combi.resize(n, true);
    fill(combi.begin(), combi.begin()+n/2, false);

}
int Cal() {
    int S=0, Y=0;
    vector<int> TeamS;
    vector<int> TeamY;
    for (int i=0; i<n; i++) {
        if (combi[i]==false)
            TeamS.push_back(i);
        else
            TeamY.push_back(i);
    }
    int length=TeamS.size();
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {
            S+=Score[TeamS[i]][TeamS[j]];
            Y+=Score[TeamY[i]][TeamY[j]];
        }
    }
    return abs(S-Y);
}
void Solve() {
    do {
        ret=min(ret, Cal());
    } while (next_permutation(combi.begin(), combi.end()));
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