#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int> skill;
vector<int> ret;
void Init()
{
    cin >> n;
    skill.resize(n);
    ret.resize(2*n+10);
    for (auto &i : skill)
        cin >> i;
}
void Solve()
{
    int number = 1;
    int front=n+5, end=n+5;
    for(auto i=skill.rbegin(); i!=skill.rend(); i++){
        if(*i==1){
            ret[front--]=number;
        }else if(*i==2){
            ret[front]=ret[front+1];
            ret[front+1]=number;
            front--;
        }else{
            ret[++end]=number;
        }
        number++;
    }

    for(int i=front+1; i<=end; i++)
        cout<<ret[i]<<" ";
    
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