#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;

vector<bool> arr;
void Solve(){
    cin>>n;
    arr.resize(n,false);
    int cnt=0;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(arr[num-1]){
            cnt++;
            continue;
        }
        arr[num-1]=true;
    }
    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}