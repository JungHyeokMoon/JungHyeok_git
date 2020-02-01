#include <bits/stdc++.h>
using namespace std;

int n;
string answer="";
string Arr[50];

void Input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>Arr[i];
    }
    
}
void Solve(){
    int len=Arr[0].size();
    char temp;
    //이중포문돌리면됨
    for(int j=0; j<len; j++){
        bool flag=false;
        for(int i=0; i<n; i++){
            if(i==0)temp=Arr[i][j];
            else{
                if(temp!=Arr[i][j]){
                    answer+="?";
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)answer+=temp;
    }

    cout<<answer<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
    return 0;
}