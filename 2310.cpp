#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
class Room{
    public:
        char type;
        int money;
        vector<int> path;
    
    Room(char type, int money, vector<int> & path){
        this->type=type;
        this->money=money;
        this->path=path;
    }
};
void dfs(int roomIdx,int money, bool & flag, vector<bool> & visited, vector<Room> & adventure,int destination){
    if(adventure[roomIdx].type=='T')
        money-=adventure[roomIdx].money;
    else if(adventure[roomIdx].type=='L'){
        if(money<adventure[roomIdx].money)
            money=adventure[roomIdx].money;
    }
    if(money<0)
        return ;
    if(roomIdx==destination){
        flag=true;
        return;
    }
    if(flag)
        return;

    visited[roomIdx]=true;
    for(auto i :adventure[roomIdx].path){
        if(!visited[i])
            dfs(i,money,flag,visited,adventure,destination);
    }
    visited[roomIdx]=false;
}
void Solve(){
    while(cin>>n){
        if(n==0)break;
        vector<Room> adventure;
        for(int i=0; i<n; i++){
            char type;
            int money;
            cin>>type>>money;
            vector<int> path;
            int roomNumber;
            while(cin>>roomNumber){
                if(roomNumber==0)break;
                path.push_back(roomNumber-1);
            }
            adventure.push_back({type,money,path});
        }
        bool flag=false;
        int money=0;
        vector<bool> visited(n,false);
        visited[0]=true;
        dfs(0,0,flag,visited,adventure,n-1);
        if(!flag)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        adventure.clear();
    }   
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}