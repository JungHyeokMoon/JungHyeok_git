#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int SwitchNum;
vector<int> Switch;
int StudentNum;
vector<pair<int,int>> Student; //성별 ,번호
void Output(){
    for(int i=1; i<=SwitchNum ; i++){
        cout<<Switch[i]<<" ";
        if(i%20==0){
            cout<<endl;
        }
    }
    cout<<endl;
} 
void Input(){
    cin>>SwitchNum;
    Switch.resize(SwitchNum+1);
    for(int i=1; i<=SwitchNum; i++){
        cin>>Switch[i];
    }
    cin>>StudentNum;
    Student.resize(StudentNum);
    for(int i=0; i<StudentNum ; i++){
        cin>>Student[i].first>>Student[i].second;
    }
    // cout<<"Init :   ";
    // Output();    
}
void BoyTurn(int num){
    for(int i=num; i<=SwitchNum; i+=num){
        Switch[i]=!Switch[i];
    }
}
void GirlTurn(int num){
    int cnt=1;
    while(true){
        if(num-cnt<1 || num+cnt>SwitchNum)break;
        if(Switch[num-cnt]!=Switch[num+cnt])break;
        // cout<<cnt<<endl;
        Switch[num-cnt]=!Switch[num-cnt];
        Switch[num+cnt]=!Switch[num+cnt];
        cnt++;
        // Output();
    }
    Switch[num]=!Switch[num];
}
void Turn(int sex,int num){
    if(sex==1)BoyTurn(num);
    else if(sex==2)GirlTurn(num);
    return ;
}
void Solve(){
    for(int i=0; i<StudentNum ; i++){
        Turn(Student[i].first,Student[i].second);
        // cout<<"ing  :   ";Output();
    }  
    // cout<<"result : ";
    Output();
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}