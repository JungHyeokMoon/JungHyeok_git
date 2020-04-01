#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string input;
void Solve(){
    getline(cin, input);
    int length=input.size();
    stack<char> stk;
    bool flag=false;
    for(int i=0; i<length; i++){
        if(input[i]==' '){
            if(!flag){
                while(!stk.empty()){
                    cout<<stk.top();
                    stk.pop();
                }
            }
            cout<<input[i];
        }
        else if(input[i]=='<'){
            while(!stk.empty()){
                cout<<stk.top();
                stk.pop();
            }
            cout<<input[i];
            flag=true;
        }
        else if(input[i]=='>'){
            flag=false;
            cout<<input[i];
        }
        else{
            if(!flag){
                stk.push(input[i]);
            }
            else{
                cout<<input[i];
            }
        }
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}