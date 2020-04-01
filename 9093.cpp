#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int t;
void Solve(){
    cin>>t;
    cin.ignore();
    for(int i=0; i<t ; i++){
        string temp;
        getline(cin,temp);
        // cout<<temp<<endl;
        int length=temp.size();
        stack<char> stk;
        for (int i = 0; i < length; i++)
        {
            if(temp[i]==' '){
                while(!stk.empty()){
                    cout<<stk.top();
                    stk.pop();
                }
                cout<<temp[i];
            }else{
                stk.push(temp[i]);
            }
        }
        while(!stk.empty()){
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
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