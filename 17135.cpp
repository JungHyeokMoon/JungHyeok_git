#include <bits/stdc++.h>	
#define endl "\n"	
using namespace std;
int n,m,d;
vector<vector<int>> Defense;
vector<vector<int>> C_Defense;
vector<int> archer;
vector<bool> select; //궁수 조합짤때
int ret=-1e9;
void Copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            C_Defense[i][j]=Defense[i][j];
        }
    }
}
void Input(){
    cin>>n>>m>>d;
    select.resize(m,false);//궁수고르기용
    Defense.resize(n,vector<int>(m,0));
    C_Defense.resize(n,vector<int>(m,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>Defense[i][j];
        }
    }
}
bool Check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(C_Defense[i][j])return false;
        }
    }
    return true;
}
void Down(){
    for(int j=0; j<m; j++){
        for(int i=n-1; i>=1; i--){
            C_Defense[i][j]=C_Defense[i-1][j];
        }
        C_Defense[0][j]=0;
    }
}
const int dy[4]={0,-1,1,0};
const int dx[4]={-1,0,0,1};
bool isinside(int y, int x){
    if(y>=0 && y<n && x>=0 && x<m){
        return true;
    }
    return false;
}
void Output(){
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cout<<C_Defense[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int Calcul(){
    int Remove_Enemy=0;
    while(!Check()){
        queue<pair<int,int>> willBeRemoved;
        for(int i=0; i<3; i++){
            vector<vector<bool>>visited;
            visited.resize(n,vector<bool>(m,false));
            visited[n-1][archer[i]]=true;
            queue<pair<pair<int,int>,int>> q;
            q.push({{n-1,archer[i]},1});
            while(!q.empty()){
                int hy=q.front().first.first;
                int hx=q.front().first.second;
                int hd=q.front().second;
                q.pop();
                if(C_Defense[hy][hx]==1){
                    willBeRemoved.push({hy,hx});
                    // cout<<"hy : "<<hy<<" hx : "<<hx<<endl;
                    break;
                }
                if(hd+1>d)continue;
                for(int i=0; i<4 ;i++){
                    int ny=hy+dy[i];
                    int nx=hx+dx[i];
                    if(!isinside(ny,nx))continue;
                    if(visited[ny][nx])continue;
                    q.push({{ny,nx},hd+1});
                }
            }
        }
        while(!willBeRemoved.empty()){
            int hy=willBeRemoved.front().first;
            int hx=willBeRemoved.front().second;
            // cout<<"hy : "<<hy<<" hx : "<<hx<<endl;
            willBeRemoved.pop();
            if(C_Defense[hy][hx]==1){
                C_Defense[hy][hx]=0;
                Remove_Enemy++;
            }
        }
        Down();
        // Output();
    }
    return Remove_Enemy;
}
void Make_Position(int idx){
    if(archer.size()==3){
        Copy();
        ret=max(ret,Calcul());
        return ;
    }
    for(int i=idx ;i<m; i++){
        if(!select[i]){
            select[i]=true;
            archer.push_back(i);
            Make_Position(i+1);
            archer.pop_back();
            select[i]=false;
        }
    }
}

void Solve(){
    Make_Position(0);
    cout<<ret<<endl;
}
int main(){	
    ios_base::sync_with_stdio(0);	
    cin.tie(0);	
    cout.tie(0);
    Input();
    Solve();
    return 0;
}