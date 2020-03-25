#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<string>arr;
string ret;
int retcount=0;
//ACGT
void Input(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}
void Solve(){
    for(int i=0; i<m; i++){
        map<char ,int> m;
        for(int j=0; j<n; j++){
            m[arr[j][i]]++;
        }
        int temp=-987654321;
        char temp2;
        for(map<char,int>::iterator it =m.begin(); it!=m.end(); it++){
            // cout<<(*it).first<<" "<<(*it).second<<" ";
            if(temp<(*it).second){
                temp=(*it).second;
                temp2=(*it).first;
            }
        }
        ret+=temp2;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(ret[i]!=arr[j][i]){
                retcount++;
            }
        }
    }
    cout<<ret<<endl<<retcount<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}