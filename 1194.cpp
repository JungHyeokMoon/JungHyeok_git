#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
vector<vector<char>> MAP;
// int keyList=0;
pair<int,int> start;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
bool IsInside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m)
        return true;
    return false;
}
void Init(){
    cin>>n>>m;
    MAP.resize(n,vector<char>(m));
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<m; j++){
            MAP[i][j]=temp[j];
            if(temp[j]=='0')
                start={i,j};
        }
    }
    
}
void Solve(){
    vector<vector<vector<int>>> dist(64,vector<vector<int>>(n,vector<int>(m,-1)));
    queue<tuple<int,int,int>> q;
    q.push({start.first,start.second,0});
    dist[0][start.first][start.second]=0;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int hy,hx,curKeyList;
        tie(hy,hx,curKeyList)=cur;

        // cout<<hy<<" "<<hx<<" ";
        // int tempKeyList=curKeyList;
        // string temp;
        // while(tempKeyList!=0){
        //     temp.push_back((tempKeyList%2)+'0');
        //     tempKeyList/=2;
        // }
        // while(temp.size()!=6){
        //     temp.push_back('0');
        // }
        // reverse(temp.begin(),temp.end());
        // cout<<temp<<" "<<dist[curKeyList][hy][hx]<<endl;

        if(MAP[hy][hx]=='1'){
            cout<<dist[curKeyList][hy][hx]<<endl;
            return ;
        }

        for(int i=0; i<4; i++){
            int ny=hy+dir[i].first;
            int nx=hx+dir[i].second;

            if(!IsInside(ny,nx))continue;
            if(MAP[ny][nx]=='#')continue;
            if(dist[curKeyList][ny][nx]!=-1)continue;
            if(MAP[ny][nx]=='.' || MAP[ny][nx]=='1' || MAP[ny][nx]=='0'){
                q.push({ny,nx,curKeyList});
                dist[curKeyList][ny][nx]=dist[curKeyList][hy][hx]+1;
            }else if('A'<=MAP[ny][nx]&& MAP[ny][nx]<='F'){
                // if(ny==0 && nx==3){
                //     cout<<"here"<<endl;
                // }
                char temp=tolower(MAP[ny][nx]);
                if((curKeyList & (1<<(temp-'a')))==(1<<(temp-'a'))){
                    // cout<<"here2"<<endl;
                    q.push({ny,nx,curKeyList});
                    dist[curKeyList][ny][nx]=dist[curKeyList][hy][hx]+1;
                }
            }else if('a'<=MAP[ny][nx] && MAP[ny][nx]<='z'){
                char temp=MAP[ny][nx];
                int nextKeyList=curKeyList | (1<<(temp-'a'));
                // curKeyList= curKeyList | (1<<(temp-'a'));
                q.push({ny,nx,nextKeyList});
                dist[nextKeyList][ny][nx]=dist[curKeyList][hy][hx]+1;
            }
        }
    }

    cout<<-1<<endl;
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