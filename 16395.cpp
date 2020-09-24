#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k;
vector<vector<int>> pascal;
void Init(){
    cin>>n>>k;
    pascal.resize(n);
    for(int i=0; i<n; i++){
        pascal[i].resize(i+1,-1);
        pascal[i][0]=1;
        pascal[i].back()=1;
    }
    

    
}
void Solve(){
    for(int i=2; i<n; i++){
        for(int j=1; j<pascal[i].size()-1; j++){
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
    cout<<pascal[n-1][k-1]<<endl;
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