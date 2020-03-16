#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
typedef pair<pair<int,int>,int> pii;
vector<pii> arr;
map<int,int>nation;
bool compare (pii & a, pii & b){
    if(a.second>b.second){
        return true;
    }
    return false;
}
void output(){
    for(int i=0; i<n; i++){
        cout<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<endl;
    }
}
void Input(){
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
    }
    // output();
    // cout<<"\\\\\\\\\\\\\\"<<endl;
}

void Solve(){
    sort(arr.begin(),arr.end(),compare);
    // output();
    int cnt=0;
    for(int i=0; i<n; i++){
        if(cnt==3){
            break;
        }
        if(nation[arr[i].first.first]>=2){
            continue;
        }
        cout<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
        nation[arr[i].first.first]++;
        cnt++;
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}