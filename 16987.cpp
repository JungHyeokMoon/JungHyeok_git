#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int ret=-987654321;
int cnt=0;
void solve(int idx){
    if(idx>=n){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(v[i].first<=0){
                cnt++;
            }
        }
        ret=max(ret,cnt);
        return ;
    }
    if(v[idx].first<=0){
        solve(idx+1);
        return ;
    }
    bool flag=true;

    for(int i=0; i<n; i++){
        if(i==idx|| v[i].first<=0)continue;
        flag=false;
        v[i].first-=v[idx].second;
        v[idx].first-=v[i].second;

        solve(idx+1);

        v[i].first+=v[idx].second;
        v[idx].first+=v[i].second;

    }
    if(flag)solve(idx+1);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n;
    v.resize(n);
    for(int i=0; i<n ; i++){
        cin>>v[i].first>>v[i].second;//내구도, 무게
    }

    solve(0);
    cout<<ret<<"\n";
}