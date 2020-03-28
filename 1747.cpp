#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
bool isvisited[1004001]={false};
vector<int> sosu;
int length;
void eratos(){
    isvisited[0]=true;
    isvisited[1]=true;
    for(int i=2; i*i<=1004000; i++){
        if(!isvisited[i]){
            for(int j=2*i; j<=1004000; j=j+i){
                isvisited[j]=true;
            }
        }
    }
    
    for(int i=2; i<=1004000; i++){
        if(!isvisited[i])sosu.push_back(i);
    }
    length=sosu.size();
    // cout<<length<<endl;
    // cout<<sosu.back()<<endl;
}
int findIndex(int num){
    for(int i=0; i<length; i++){
        if(sosu[i]>=num){
            return i;
        }
    }
}
void Solve(){
    cin>>n;
    eratos();
    int Startidx=findIndex(n);
    for(int i=Startidx; i<length; i++){
        string original=to_string(sosu[i]);
        string reversenum="";
        int templeng=original.size();
        for(int j=templeng-1; j>=0 ;j--){
            reversenum+=original[j];
        }
        if(original==reversenum){
            cout<<original<<endl;
            return ;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}