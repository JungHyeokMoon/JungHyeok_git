#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;

int a,b;
int cnt=0;
int Enum[2]={4,7};
void backTrack(string str){
    if(!str.empty()){
        long long num=stol(str);
        if(num>b){
            return ;
        }
        if(num>=a){
            cnt++;
        }
    }
    for(int i=0; i<2; i++){
        str.push_back(char(Enum[i]+'0'));
        backTrack(str);
        str.pop_back();
    }

}
void Solve(){
    cin>>a>>b;
    backTrack("");
    cout<<cnt<<endl;
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Solve();
    return 0;
}