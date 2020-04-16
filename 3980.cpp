#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int c;
// vector<vector<int>> Player;
vector<pair<int,int>> Ability[11]; //몇번째 위치 , 능력치
vector<bool> PlayerCheck;
vector<bool> Position;
int ret=-1e9;
int sum=0;
bool Check(){
    for(int i=0; i<11; i++){
        if(!PlayerCheck[i])return false;
    }
    return true;
}
void Lineup(int idx){
    if(idx==11){
        if(Check()){
            ret=max(ret,sum);
        }
        return ;
    }

    for(int i=idx; i<11; i++){
        for(int j=0; j<Ability[i].size(); j++){
            if(!Position[Ability[i][j].first]){
                Position[Ability[i][j].first]=true;
                sum+=Ability[i][j].second;
                PlayerCheck[i]=true;
                Lineup(i+1);
                PlayerCheck[i]=false;
                sum-=Ability[i][j].second;
                Position[Ability[i][j].first]=false;
            }
        }
    }
}
void Init(){
    for(int i=0; i<11; i++){
        Ability[i].clear();
        fill(Position.begin(),Position.end(),false);
        fill(PlayerCheck.begin(),PlayerCheck.end(),false);
        ret=-1e9;
        sum=0;
    }
}
void Input(){
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            int num;
            cin>>num;
            if(num){
                Ability[i].push_back({j,num}); //몇번째 포지션, 능력치
            }
        }
    }
}
void Solve(){
    cin>>c;
    Position.resize(11,false);
    PlayerCheck.resize(11,false);
    while(c--){
        Init();
        Input();
        Lineup(0);
        cout<<ret<<endl;
    }
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Solve();
    return 0;
}


// for(int i=0; i<11; i++){
//             cout<<"Player "<<i<<" : ";  
//             for(int j=0; j<Ability[i].size(); j++){
//                 cout<<Ability[i][j].first<<" "<<Ability[i][j].second<<"\\ ";
//             }
//             cout<<endl;
//         }
