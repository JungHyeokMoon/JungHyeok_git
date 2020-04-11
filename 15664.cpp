#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<bool> visited;
vector<int> arr;
vector<int> Combi;
set<string> s;
void Input(){
    cin>>n>>m;
    visited.resize(n,false);
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
}
void Make_Combi(int depth,int idx){
    if(depth==m){
        string temp="";
        int length=Combi.size();
        for(int i=0; i<length; i++){
            temp+=(Combi[i]+'0');
            if(i!=length-1){
                temp.push_back(' ');
            }
        }
        if(s.find(temp)==s.end()){
            s.insert(temp);
            for(int i=0; i<length; i++){
                cout<<Combi[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }

    for(int i=idx; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            Combi.push_back(arr[i]);
            Make_Combi(depth+1,i+1);
            Combi.pop_back();
            visited[i]=false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Make_Combi(0,0);
    return 0;
}