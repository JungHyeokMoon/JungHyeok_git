#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int t;
int n;
void Solve(){
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i].first>>v[i].second;
        }
        
        sort(v.begin(), v.end());
        
        
        int cnt=1;
        int temp=v[0].second;
        for(int i=1; i<n; i++){
            if(temp>v[i].second){
                temp=v[i].second;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}