#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string number;

void Input(){
    cin>>number;
}

void Solve(){
    int length=number.size();
    int idx=1;
    while(idx<length){
        long long prefix=1;
        long long suffix=1;
        for(int i=0; i<idx; i++){
            prefix*=(number[i]-'0');
        }
        for(int i=idx; i<length ; i++){
            suffix*=(number[i]-'0');
        }

        if(prefix==suffix){
            cout<<"YES"<<endl;
            return ;
        }
        // cout<<prefix<<" "<<suffix<<endl;
        idx++;
    }
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;   
}