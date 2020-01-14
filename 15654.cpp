#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;
vector<int> ret;
bool visited[10000];
void n_m(int cnt){
    if(cnt==m){
        for(auto i: ret)cout<<i<<" ";
        cout<<"\n";
        return ;
    }
    for(int i=0; i<n; i++){
        if(!visited[arr[i]]){
            ret.push_back(arr[i]);
            visited[arr[i]]=true;
            n_m(cnt+1);
            visited[arr[i]]=false;
            ret.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;
    arr.resize(n);
    for(int i=0; i<n ; i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    n_m(0);
    return 0;
}