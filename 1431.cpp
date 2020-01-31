#include <bits/stdc++.h>
using namespace std;
int n;
string Arr[1000];
void Input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>Arr[i];
    }
}
bool Compare(string a, string b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    else{
        int sum1=0;
        int sum2=0;
        for(int i=0 ; i<a.size(); i++){
            if(a[i]>='0' &&a[i]<='9')sum1+=a[i]-'0';
            if(b[i]>='0' &&b[i]<='9')sum2+=b[i]-'0';
        }
        if(sum1==sum2){
            for(int i=0; i<a.size(); i++){
                if(a[i]==b[i])continue;
                return a[i]<b[i];
            }
        }
        else{
            return sum1<sum2;
        }
    }
}
void Solve(){
    sort(Arr,Arr+n,Compare);

    //cout<<"\\\\\\\\"<<"\n";
    for(int i=0; i<n; i++){
        cout<<Arr[i]<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}