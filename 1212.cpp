#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string Eight_digit;
string Eight_Arr[8]={"000","001","010","011","100","101","110","111"};
string ret="";
void Input(){
    cin>>Eight_digit;
}
void Solve(){
    int length=Eight_digit.length();
    for(int i=0; i<length; i++){
        int number=Eight_digit[i]-'0';
        if(length==1 && number==0){
            cout<<0<<endl;
            return ;
        }
        ret+=Eight_Arr[number];
        // cout<<"number : "<<number<<" , ret : "<<ret<<endl;
        if(i==0){
            int cnt=0;
            for(int j=0; j<ret.length(); j++){
                if(ret[j]=='0'){
                    cnt++;
                }
                else{
                    break;
                }
            }
            while(cnt--){
                ret.erase(ret.begin());
            }
        }
    }
    cout<<ret<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
}