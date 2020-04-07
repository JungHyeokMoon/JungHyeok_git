#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
vector<int> crane;
vector<int> box;
int Time=0;
void Input(){
    cin>>n;
    crane.resize(n);
    for(int i=0; i<n; i++)cin>>crane[i];
    cin>>m;
    box.resize(m);
    for(int i=0; i<m; i++)cin>>box[i];
    
}

void Solve(){
    sort(crane.begin(),crane.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());
    if(box[0]>crane[0]){
        cout<<-1<<endl;
        return ;
    }
    
    while(!box.empty()){
        Time++;
        
        int Index=0;
        for(int k=0; k<box.size(); k++){
            if(Index==n)break;
            if(crane[Index]>=box[k]){
                Index++;
                box.erase(box.begin()+k);
                k=k-1;
            }
        }
    }
    cout<<Time;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}