#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,k;
vector<vector<int>> Matrix;
vector<vector<int>> C_Matrix;
vector<pair<pair<int,int>,int>> V;
vector<int> order;
vector<bool> visited;
int ret=1e9;
void Copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            C_Matrix[i][j]=Matrix[i][j];
        }
    }
}
void Input(){
    cin>>n>>m>>k;
    Matrix.resize(n,vector<int>(m));
    C_Matrix.resize(n,vector<int>(m));
    V.resize(k);
    visited.resize(k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>Matrix[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>V[i].first.first>>V[i].first.second>>V[i].second;
    }
}
void Rotation(int r, int c , int s){
    // cout<<"r : "<<r<<" c: "<<c<<" s: "<<s<<endl;
    while(s>0){
        int temp=C_Matrix[r-s][c-s];

        for(int i=r-s; i<r+s; i++){
            C_Matrix[i][c-s]=C_Matrix[i+1][c-s];
        }//왼쪽열이동
        for(int j=c-s; j<c+s; j++){
            C_Matrix[r+s][j]=C_Matrix[r+s][j+1];
        }//마지막행 이동
        for(int i=r+s; i>r-s; i--){
            C_Matrix[i][c+s]=C_Matrix[i-1][c+s];
        }//마지막열 이동
        for(int j=c+s; j>c-s+1; j--){
            C_Matrix[r-s][j]=C_Matrix[r-s][j-1];
        }
        C_Matrix[r-s][c-s+1]=temp;
        s--;
    }
}
int Cal(){
    for(int i=0; i<k; i++){
        int r=V[order[i]].first.first-1;
        int c=V[order[i]].first.second-1;
        int s=V[order[i]].second;
        Rotation(r,c,s);
    }
    // cout<<endl;
    int temp=1e9;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum+=C_Matrix[i][j];
        }
        temp=min(temp,sum);
    }
    return temp;
}

void Make_Order(int cnt){
    if(cnt==k){
        Copy();
        // for(int i=0; i<k; i++){
        //     cout<<order[i]<<" ";
        // }
        // cout<<endl;
        ret=min(ret,Cal());
        return ;
    }

    for(int i=0; i<k; i++){
        if(!visited[i]){
            order.push_back(i);
            visited[i]=true;
            Make_Order(cnt+1);
            order.pop_back();
            visited[i]=false;
        }
    }
}
void Solve(){
    Make_Order(0);
    cout<<ret<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}