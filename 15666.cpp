#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> arr;
vector<int> permu;
set<string> s;
int n,m;
void Input(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
}
void Make_Permu(int depth){
    if(depth==m){
        
        string temp="";
        int length =permu.size();
        for(int i=0; i<length-1; i++){
            if(permu[i]>permu[i+1]){
                return ;
            }
        }
        for(int i=0; i<length; i++){
            temp+=(permu[i]+'0');
            if(i!=length-1){
                temp.push_back(' ');
            }
        }

        if(s.find(temp)==s.end()){
            s.insert(temp);
            for(int i=0; i<length ; i++){
                cout<<permu[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    

    for(int i=0; i<n; i++){
        permu.push_back(arr[i]);
        Make_Permu(depth+1);
        permu.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Make_Permu(0);
    return 0;
}