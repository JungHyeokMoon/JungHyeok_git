#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<string> arr;
vector<bool> visited;
int cnt=0;
void Input(){
    cin>>n;
    arr.resize(n);
    visited.resize(n,false);
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
}
void Solve(){
    for(int i=0; i<n; i++){
        string temp=arr[i];
        if(visited[i])continue;

        for(int j=0; j<temp.size(); j++){
            temp+=temp[0];
            temp.erase(temp.begin());
            for(int k=i+1; k<n; k++){
                if(temp==arr[k]){
                    visited[k]=true;
                }
            }
        }
        
        cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}