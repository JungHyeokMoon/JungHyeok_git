#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isvisited[6][6]={false};
const int dy[8]={-2,-1,1,2,2,1,-1,-2};
const int dx[8]={-1,-2,-2,-1,1,2,2,1};
bool isinside(int y, int x){
    if(y>=0 && y<6 && x>=0 && x<6){
        return true;
    }
    return false;
}
string input[36];
void Input(){
    for(int i=0; i<36; i++){
        cin>>input[i];
    }
}
pair<int,int> getcoodi(string temp){
    pair<int,int>hc; //y,x
    hc.second=temp[0]-'A';
    hc.first=5-((temp[1]-'0')-1);
    return hc;
}
void Solve(){
    pair<int,int>firstC=getcoodi(input[0]);

    pair<int,int> hc=getcoodi(input[0]);
    isvisited[hc.first][hc.second]=true;
    for(int i=1 ; i<36; i++){
        pair<int,int> nc=getcoodi(input[i]);
        int hy=hc.first;
        int hx=hc.second;
        // cout<<"hy : "<<hy<<" , hx : "<<hx<<endl;
        // cout<<"ny : "<<nc.first<<" , nx : "<<nc.second<<endl;
        bool flag=false;
        for(int j=0; j<8; j++){
            int ny=hy+dy[j];
            int nx=hx+dx[j];
            // cout<<"inner ny : "<<ny<<" , inner nx : "<<nx<<endl;
            if(!isinside(ny,nx))continue;
            if(ny==nc.first && nx==nc.second){
                if(isvisited[ny][nx]){
                    cout<<"Invalid"<<endl;
                    return ;
                }
                else{
                    isvisited[ny][nx]=true;
                    flag=true;
                    hc=nc;
                    break;
                }
            }
        }
        if(!flag){
            // cout<<"here?"<<endl;
            cout<<"Invalid"<<endl;
            return ;
        }
        
    }
    for(int i=0; i<8; i++){
        int ny=hc.first+dy[i];
        int nx=hc.second+dx[i];
        if(!isinside(ny,nx))continue;
        if(ny==firstC.first && nx==firstC.second){
            cout<<"Valid"<<endl;
            return ;
        }
    }
    cout<<"Invalid"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}