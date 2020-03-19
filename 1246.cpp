#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m; //n개의 달걀 m명의고객
int ret2=0;
vector<int> price;
pair<int,int> ret={0,0};
void Input(){
    cin>>n>>m;
    price.resize(m);
    for(int i=0; i<m; i++){
        cin>>price[i];
    }
    
}
void Solve(){
    int MAX;
    for(int i=0; i<m; i++){
        int total=n;
        MAX=price[i];
        int temp=0;
        for(int j=0; j<m; j++){
            if(price[j]>=MAX){
                total--;
                temp+=MAX;
                if(total==0){
                    if(ret.second<=temp){
                        ret.second=temp;
                        ret.first=MAX;
                    }
                    break;
                }
            }
        }
        if(ret.second<=temp){
            ret.second=temp;
            ret.first=MAX;
        }
    }
    cout<<ret.first<<" "<<ret.second<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}