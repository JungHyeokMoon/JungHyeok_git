#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> building;
int n;
long long ret;
void Input(){
    cin>>n;
    building.resize(n);
    for(int i=0; i<n; i++){
        cin>>building[i];
    }
}
void Solve(){
    // reverse(building.begin(),building.end());
    
    stack<int>stk;
    for(int i=0; i<n; i++){
        while(!stk.empty() && stk.top() <=building[i])stk.pop(); //스택을 순 감소 형태로 만들어줘야함
        ret+=(long long)stk.size();
        stk.push(building[i]);
    }

    cout<<ret<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}