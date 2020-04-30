#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n,m,k;
vector<vector<int>> arr;
vector<int> zerocnt;
vector<int> isOk;
void Input(){
    cin>>n>>m;
    arr.resize(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin>>temp;
        for(int j=0; j<m; j++){
            arr[i][j]=temp[j]-'0';
        }
    }
    zerocnt.resize(n,0);
    cin>>k;
    
}

void Zerocount(){
    for(int i=0; i<n; i++){
        for(int j=0; j < m; j++){
            if(arr[i][j]==0){
                zerocnt[i]++;
            }
        }
    }
}
void Solve(){
    Zerocount();
    
    for(int i=0; i<n; i++){
        if(zerocnt[i]%2==k%2 && zerocnt[i]<=k){
            isOk.push_back(i);
        }
    }
    
    if(isOk.empty()){
        cout<<0<<endl;
        return ;
    }

    int Max=-987654321;
    int length=isOk.size();
    for(int i=0; i<length; i++){
        int cnt=0;
        for(int j=0; j<length; j++){
            bool flag=true;
            for(int l=0; l<m; l++){
                if(arr[isOk[i]][l]!=arr[isOk[j]][l]){
                    flag=false;
                    break;
                }
            }
            if(flag)cnt++;
            Max=max(Max,cnt);
        }
    }

    cout<<Max<<endl;
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Input();
    Solve();
    return 0;
}