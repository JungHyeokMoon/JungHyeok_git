#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int t;
void Solve(){
    cin>>t;
    for(int i=0; i<t; i++){
        int number;
        cin>>number;

        long long cnt=0;
        for(int i=5; i<=number ; i=i*5){
            cnt+=number/i;
        }
        cout<<cnt<<endl;
    } 
    //팩토리얼 의 0의숫자를 세기위해서는 10이 얼마나 있는지세면된다 
    //숫자를 소인수분해했을때 2와 5의갯수 중 작은것을 정답으로하면되는데
    //2는워낙많다 그래서 5만해주면되고, 5에서끝나는게아니라 5,25,125,, 등까지해줘야함
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}