#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,c;
vector<int> wifi;
void Init(){
    cin>>n>>c;
    wifi.resize(n);
    for(auto & i: wifi)
        cin>>i;
}
void Solve(){
    sort(wifi.begin(),wifi.end());
    int left=1;
    int right=wifi.back()-wifi.front();
    int ret=0;
    int d=0;
    while(left<=right){
        int mid=(left+right)/2;
        int setNum=1;
        int before=wifi[0];
        for(int i=1; i<n; i++){
            d=wifi[i]-before;
            if(wifi[i]-before>=mid){
                setNum++;
                before=wifi[i];
            }
        }

        if(setNum>=c){
            ret=mid;
            left=mid+1;
        }else
            right=mid-1;
    }
    cout<<ret<<endl;
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