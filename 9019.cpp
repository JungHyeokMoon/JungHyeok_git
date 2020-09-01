#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int t;
int dlsrOperation(int number, int idx){
    if(idx==0){
        number*=2;
        return number>=10000 ? number%10000 : number;
    }else if(idx==1){
        number-=1;
        return number==-1? 9999: number;
    }
    else if(idx==2){
        int m=number/1000;
        return (number%1000)*10+m;
    }else{
        int m=(number%10)*1000;
        return m+number/10;
    }
}
void bfs(int start, int end){
    vector<bool> visited(10000,false);
    vector<pair<int,char>> dlsrRegister(10000);
    queue<int> q;
    visited[start]=true;
    q.push(start);

    bool flag=false;
    while(!q.empty()){
        int hNum=q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nNum=dlsrOperation(hNum,i);
            if(nNum<0 || nNum>=10000) continue;
            if(visited[nNum])continue;

            if(i==0){
                dlsrRegister[nNum]={hNum,'D'};
            }else if(i==1){
                dlsrRegister[nNum]={hNum,'S'};
            }else if(i==2){
                dlsrRegister[nNum]={hNum,'L'};
            }else{
                dlsrRegister[nNum]={hNum,'R'};
            }
            
            
            visited[nNum]=true;
            q.push(nNum);
            if(nNum==end){
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }

    string command;
    while(end!=start){
        command.push_back(dlsrRegister[end].second);
        end=dlsrRegister[end].first;
    }

    reverse(command.begin(),command.end());
    cout<<command<<endl;
}
void Solve(){
    cin>>t;
    for(int i=0; i<t; i++){
        int A,B;
        cin>>A>>B;
        bfs(A,B);
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