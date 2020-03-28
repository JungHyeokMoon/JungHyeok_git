#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<pair<int,int>> v;
int maximumDate;
long long ret;
    
bool compare(pair<int,int> &a , pair<int ,int> & b){
    if(a.second<b.second){
        return true;
    }
    else if(a.second==b.second){
        if(a.first>b.first){
            return true;
        }
    }   
    return false;
}//day순정렬

void Input(){
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),compare);
    
}
void Solve(){
    priority_queue<int,vector<int>,greater<int>> pq;//top에 제일작은것이 올라와있다.
    for(int i=0; i<n; i++){
        ret+=v[i].first;
        pq.push(v[i].first);//날짜순 정렬해놓고 pq에 cost값넣어줌 //최대값을구하려면 전체-최소
        if(pq.size()>v[i].second){//원래는 이익순으로 정렬해놓고 visited이용해서 제일 거리가 먼것더해주면되는데 시간복잡도가크다
            ret-=pq.top();
            pq.pop();
        }
    }
    cout<<ret<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}