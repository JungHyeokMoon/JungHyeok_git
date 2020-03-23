#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
typedef pair<pair<int,int>,pair<int,int>> pp;
vector<pair<int,int>> v;
void Input(){
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++){
        pp input;
        cin>>input.first.first>>input.first.second>>input.second.first>>input.second.second;
        v[i].first=input.first.first*100+input.first.second;
        v[i].second=input.second.first*100+input.second.second;
    }
}

void Solve(){
    sort(v.begin(),v.end());
    int idx=-1;
    int temp=0;
    int result=0;
    for(int i=301; i<=1130 && idx<n ; i=temp){
        bool flag=false;
        idx++;
        for(int j=idx; j<n; j++){
            if(v[j].first>i){
                break;
            }
            else if(temp<v[j].second){
                temp=v[j].second;
                idx=j;

                flag=true;
            }
        }
        if(flag){
            result++;
        }
        else{
            cout<<0<<endl;
            return ;
        }
        
    }
    cout<<result<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}