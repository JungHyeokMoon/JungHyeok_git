#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int t,n,m;

int num;
void Solve(){
    cin>>t;
    while(t--){
        cin>>n;
        unordered_set<int> note1;
        for(int i=0; i<n; i++){
            cin>>num;
            note1.insert(num);
        }
        cin>>m;
        for(int i=0; i<m ; i++){
            cin>>num;
            if(note1.count(num)==1){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}