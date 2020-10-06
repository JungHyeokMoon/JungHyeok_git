#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
priority_queue<long long> pq;
void Init(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        pq.push(-num);
    }
    
}
void Solve(){
    for(int i=0; i<m; i++){
        long long firstNumber=-pq.top();
        pq.pop();
        long long secondNumber=-pq.top();
        pq.pop();
        long long sum=firstNumber+secondNumber;
        pq.push(-sum);
        pq.push(-sum);
    }

    long long sum=0;
    while(!pq.empty()){
        sum+=-pq.top();
        pq.pop();
    }
    cout<<sum<<endl;
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