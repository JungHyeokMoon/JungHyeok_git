#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,k;
set<string> ret;
vector<int> number;
void Init(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        number.push_back(num);
    }
    
}
void Solve(){
    sort(number.begin(),number.end());
    do{
        string tempRet;
        for(int i=0; i<k; i++)
            tempRet+=to_string(number[i]);
        ret.insert(tempRet);
    }while(next_permutation(number.begin(),number.end()));

    cout<<ret.size()<<endl;
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