#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool visited[1000001];
vector<int> arr;
void eratos(){
    visited[0]=true;
    visited[1]=true;
    for(int i=2; i*i<=1000000; i++){
        if(!visited[i]){
            for(int j=2*i; j<=1000000; j=j+i){
                visited[j]=true;
            }
        }
    }

    for(int i=2; i<=1000000; i++){
        if(!visited[i]){
            arr.push_back(i);
        }
    }
    
}
void Solve(){
    eratos();
    int num;
    int length=arr.size();
    while(cin>>num){
        if(num==0){
            break;
        }
        bool flag=false;
        for(int i=0; i<length; i++){
            int temp=arr[i];
            if(!visited[num-temp]){//두수의 합을구할때(num) 한수 가 p 이라면 나머지수는 num-p일수밖에없다.
                cout<<num<<" = "<<temp<<" + "<<num-temp<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"Goldbach's conjecture is wrong."<<endl;
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