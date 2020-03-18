#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
string str;
vector<vector<char>> arr;
bool isinside(int y ,int x){
    if(y>=0 && y<n &&x>=0 &&x<n){
        return true;
    }
    return false;
}
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
void Input(){
    cin>>n>>str;
    arr.resize(n);
    for(int i=0; i<n; i++){
        arr[i].resize(n,'.');
    }
    
    
}
void output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
void Solve(){
    pair<int,int> hc={0,0};
    pair<int,int> nc={0,0};
    int direction=-1;
    for(int i=0; i<str.size(); i++){
        // cout<<"hc : "<<hc.first<<" "<<hc.second<<endl;
        char temp=str[i];
        // cout<<temp<<endl;
        if(temp=='U'){
            direction=0;
        }else if(temp=='L'){
            direction=1;
        }else if(temp=='D'){
            direction=2;
        }else if(temp=='R'){
            direction=3;
        }
        // cout<<"direction : "<<direction<<endl;
        if(!isinside(hc.first+dy[direction],hc.second+dx[direction]))continue;
        
        nc.first=hc.first+dy[direction];
        nc.second=hc.second+dx[direction];
        // cout<<"nc : "<<nc.first<<" "<<nc.second<<endl;
        // cout<<endl;
        pair<int,int> flagdec={nc.first-hc.first,nc.second-hc.second}; //수직수평판단
        
        bool flag; //false 수직, true 수평
        if(flagdec.second==0){
            flag=false;
        }else{
            flag=true;
        }
        // cout<<"hy : "<<hc.first<<" , hx : "<<hc.second<<" , ny : "<<nc.first<<" , nx : "<<nc.second<<" , flag"<<flag<<endl;

        if(flag){//수평
            if(arr[hc.first][hc.second]=='+'){
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='-';
                }
                else if(arr[nc.first][nc.second]=='|'){
                    arr[nc.first][nc.second]='+';
                }
            }
            else if(arr[hc.first][hc.second]=='-'){
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='-';
                }
                else if(arr[nc.first][nc.second]=='|'){
                    arr[nc.first][nc.second]='+';
                }
            }
            else if(arr[hc.first][hc.second]=='.'){
                arr[hc.first][hc.second]='-';
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='-';
                }
                else if(arr[nc.first][nc.second]=='|'){
                    arr[nc.first][nc.second]='+';
                }
            }
            else if(arr[hc.first][hc.second]=='|'){
                arr[hc.first][hc.second]='+';
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='-';
                }
                else if(arr[nc.first][nc.second]=='|'){
                    arr[nc.first][nc.second]='+';
                }
            }
        }
        else{
            if(arr[hc.first][hc.second]=='+'){
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='|';
                }else if(arr[nc.first][nc.second]=='-'){
                    arr[nc.first][nc.second]='+';
                }
            }
            else if(arr[hc.first][hc.second]=='-'){
                arr[hc.first][hc.second]='+';
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='|';
                }else if(arr[nc.first][nc.second]=='-'){
                    arr[nc.first][nc.second]='+';
                }

            }else if(arr[hc.first][hc.second]=='.'){
                arr[hc.first][hc.second]='|';
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='|';
                }else if(arr[nc.first][nc.second]=='-'){
                    arr[nc.first][nc.second]='+';
                }

            }else if(arr[hc.first][hc.second]=='|'){
                if(arr[nc.first][nc.second]=='.'){
                    arr[nc.first][nc.second]='|';
                }else if(arr[nc.first][nc.second]=='-'){
                    arr[nc.first][nc.second]='+';
                }

            }
        }
        hc=nc;
        
    }
    // cout<<hc.first<<" "<<hc.second<<endl;
    // cout<<nc.first<<" "<<nc.second<<endl;
    output();
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}