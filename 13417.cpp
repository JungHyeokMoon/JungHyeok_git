#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t;
void Solve(){
    cin>>t;
    while(t--){
        int n;
        deque<char> dq;
        cin>>n;
        for(int i=0; i<n; i++){
            char input;
            cin>>input;
            if(dq.empty())dq.push_front(input);
            else if(dq.front()>=input)
                dq.push_front(input);
            else
                dq.push_back(input);
        }
        while(!dq.empty()){
            cout<<dq.front();
            dq.pop_front();
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}