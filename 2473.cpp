#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<long long> arr;
long long minimum=LLONG_MAX;
tuple<int,int,int> ret;
void Init(){
    cin>>n;
    arr.resize(n);
    for(auto & i :arr)
        cin>>i;
}

void Solve(){
    sort(arr.begin(),arr.end());
    for(int i=0; i<n-2; i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            long long temp=arr[i]+arr[j]+arr[k];
            if(llabs(temp)<minimum){
                minimum=llabs(temp);
                ret=make_tuple(arr[i],arr[j],arr[k]);
            }

            if(temp>0)
                k--;
            else{
                j++;
            }
        }
    }
    int i,j,k;
    tie(i,j,k)=ret;
    cout<<i<<" "<<j<<" "<<k<<endl;
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