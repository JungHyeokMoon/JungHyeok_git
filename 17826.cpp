#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> score;
int myScore=-1;
void Init(){
    int num;
    while(cin>>num){
        score.push_back(num);
    }
    myScore=score.back();
    score.pop_back();
    // for(auto i : score)
    //     cout<<i<<endl;
}
void Solve(){
    int cnt=1;
    for(auto i :score){
        if(i==myScore){
            break;
        }
        cnt++;
    }
    if(cnt<6)
        cout<<"A+"<<endl;
    else if(cnt<16)
        cout<<"A0"<<endl;
    else if(cnt<31)
        cout<<"B+"<<endl;
    else if(cnt<36)
        cout<<"B0"<<endl;
    else if(cnt<46)
        cout<<"C+"<<endl;
    else if(cnt<49)
        cout<<"C0"<<endl;
    else
        cout<<"F"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    Solve();
    return 0;
}