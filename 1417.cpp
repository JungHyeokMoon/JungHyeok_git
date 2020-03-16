#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
vector<pair<int,bool>> arr;
// vector<int> arr;
int dasom;
bool compare(pair<int,bool> & a , pair<int,bool> & b){
    if(a.first<b.first)
        return true;
    else if(a.first==b.first){
        a.second<b.second;
    }
    return false;
}
void Input(){
    cin>>n;
    // cin>>dasom;
    // arr.resize(n-1);
    // for(int i=0; i<n-1; i++){
    //     cin>>arr[i];
    // }
    arr.resize(n,{0,false});
    arr[0].second=true;
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
    }
}
int findIndex(){
    for(int i=0; i<n; i++){
        if(arr[i].second==true)return i;
    }
}
// void print(){
//     for(int i=0; i<n; i++){
//         cout<<"pyo : "<<arr[i].first<<" , flag : "<<arr[i].second<<" ";
//     }
//     cout<<endl;
// }
void Solve(){
    if(arr.size()==1){
        cout<<0<<endl;
        return;
    }
    int cnt=0;
    while(arr[n-1].second!=true){
        sort(arr.begin(),arr.end(),compare);
        // print();
        int idx=findIndex();
        arr[n-1].first-=1;
        arr[idx].first+=1;
        cnt++;
    }   

    cout<<cnt-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}