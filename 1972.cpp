#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void Print(string & str, bool flag){
    if(flag)
        cout<<str<<" is surprising."<<endl;
    else
        cout<<str<<" is NOT surprising."<<endl;
    
}
void Solve(){
    string input;
    while(cin>>input){
        if(input=="*")break;
        
        int length=input.size();
        bool flag=true;
        for(int i=0; i<=length-2; i++){//0-쌍~ N-2쌍
            set<string> S;
            for(int j=0; j<length-(i+1); j++){
                string temp;
                temp.push_back(input[j]);
                temp.push_back(input[j+i+1]);
                if(S.find(temp)!=S.end()){
                    flag=false;
                    break;
                }
                else
                    S.insert(temp);
            }  
            if(!flag)break;
        }
        Print(input,flag);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}