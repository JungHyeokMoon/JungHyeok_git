#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int> potion;
void Init(){
    cin>>n;
    potion.resize(n);
    for(auto & i:potion)
        cin>>i;
}
void Solve(){
    pair<int,int> ret={potion[0],potion.back()};
    int s=0, e=potion.size()-1;
    int temp=INT32_MAX;
    while(s<e){
        
        int sum=potion[s]+potion[e];
        // cout<<s<<" "<<e<<" "<<sum<<endl;
        if(abs(sum)==0){
            ret={potion[s],potion[e]};
            break;
        }else{
            if(abs(sum)<temp){
                temp=abs(sum);
                ret={potion[s],potion[e]};
            }
            
            if(sum>0)e--;
            else s++;
        }

    }
    cout<<ret.first<<" "<<ret.second<<endl;
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