#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
string temp;
vector<int> arr;
void Input(){
    cin>>n>>temp;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
} 
void Solve(){
    int length=temp.size();
    stack<double> stk;
    // int idx=0;
    for(int i=0; i<length; i++){
        if('A'<=temp[i] && temp[i]<='Z'){
            stk.push(double(arr[temp[i]-'A']));
        }
        else{
            double temp1=stk.top();
            stk.pop();
            double temp2=stk.top();
            stk.pop();
            double pushnum=0;
            if(temp[i]=='*'){
                pushnum=temp1*temp2;
            }else if(temp[i]=='+'){
                pushnum=temp1+temp2;
            }else if(temp[i]=='/'){
                pushnum=temp2/temp1;
            }else {
                pushnum=temp2-temp1;
            }
            stk.push(pushnum);
        }
    }

    cout<<fixed;
    cout.precision(2);
    cout<<stk.top()<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}