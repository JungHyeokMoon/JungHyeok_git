#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> arr;
int ret=0;

void Input(){
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}
void Solve(){
    for(int i=0; i<n ; i++){
        stack<char> stk;
        string temp=arr[i];
        int length=temp.size();
        for(int j=0; j<length; j++){
            if(stk.empty()){
                stk.push(temp[j]);
                continue;
            }
            else if (stk.top()==temp[j]){
                stk.pop();
            }
            else{
                stk.push(temp[j]);
            }
        }
        if(stk.empty()){
            ret++;
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

    return 0;
}