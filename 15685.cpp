// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;

// const int MAX=100+1;
// bool MAP[MAX][MAX]={false};
// int n;
// const int dy[4]={0,-1,0,1}; // 오른쪽, 위쪽,왼쪽,아래쪽
// const int dx[4]={1,0,-1,0};
// int Count(){
//     int cnt=0;
//     for(int i=0; i<MAX-1; i++){
//         for(int j=0; j<MAX-1; j++){
//             if(MAP[i][j] && MAP[i][j+1] && MAP[i+1][j] && MAP[i+1][j+1]) cnt++;
//         }
//     }
//     return cnt;
// }
// void Solve(){
//     cin>>n;
//     for(int i=0; i<n ; i++){
//         int y,x,d,g;
//         cin>>x>>y>>d>>g;
//         vector<int> curve;
//         curve.push_back(d);
//         for(int j=0; j<g; j++){
//             vector<int> temp=curve;
//             int templength=temp.size();
//             for(int k=templength-1; k>=0; k--){
//                 curve.push_back((temp[k]+1)%4);
//             }
//         }
//         MAP[y][x]=true;
//         int curvelength=curve.size();
//         for(int j=0; j<curvelength; j++){
//             y+=dy[curve[j]];
//             x+=dx[curve[j]];

//             MAP[y][x]=true;
//         }
//     }

//     cout<<Count()<<endl;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     Solve();
//     return 0;
// }

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<tuple<int,int,int,int>> dragonCurve;
vector<vector<bool>> visited;
pair<int,int> dir[4]={{0,1},{-1,0},{0,-1},{1,0}};//오른 위 왼 아래
void Init(){
    visited.resize(101,vector<bool>(101,false));
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        dragonCurve.push_back(make_tuple(x,y,d,g));
    }

}
int Count(){
    int cnt=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(visited[i][j]&&
                visited[i+1][j]&&
                visited[i][j+1]&&
                visited[i+1][j+1])cnt++;
        }
    }
    return cnt;
}
void Solve(){
    for(int i=0; i<n; i++){
        int x, y,d,g;
        tie(x, y,d,g)=dragonCurve[i];
        
        vector<int> curve;
        curve.push_back(d);
        for(int j=0; j<g; j++){
            vector<int> temp=curve;
            int templength=temp.size();
            for(int k=templength-1; k>=0; k--){
                curve.push_back((temp[k]+1)%4);
            }
        }

        visited[y][x]=true;
        int curvelength=curve.size();
        for(int j=0; j<curvelength; j++){
            y+=dir[curve[j]].first;
            x+=dir[curve[j]].second;
            visited[y][x]=true;
        }
    }
    cout<<Count()<<endl;
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