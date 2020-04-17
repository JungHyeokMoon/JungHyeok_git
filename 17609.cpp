#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int t;
bool distinction1(string str){
    int s=0, e=str.size()-1;
    while(s<=e){
        if(str[s++]!=str[e--]){
            return false;
        }
    }
    return true;
}
bool distinction2(int s,int e, string  &str,bool check){
    if(s>e)return true;
    else if (str[s]==str[e]) return distinction2(s+1,e-1,str,check);
    else if (check) return max(distinction2(s+1,e,str,false),distinction2(s,e-1,str,false));
    else return false;
}
void Solve(){
    cin>>t;
    for(int i=0; i<t; i++){
        string input;
        cin>>input;
        if(distinction1(input))cout<<0<<endl;
        else if(distinction2(0,input.size()-1,input,true))cout<<1<<endl;
        else cout<<2<<endl;
    }
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Solve();
    return 0;
}