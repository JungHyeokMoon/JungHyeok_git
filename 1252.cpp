#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string temp1;
string temp2;

void Input(){
    cin>>temp1>>temp2;
}
void Solve(){
    int length1=temp1.size();
    int length2=temp2.size();
    int maxLength=max(length1,length2);
    if(length1>length2){
        for(int i=0; i<length1-length2; i++){
            temp2.insert(temp2.begin(),'0');
        }
    }
    else if(length1<length2){
        for(int i=0; i<length2-length1; i++){
            temp1.insert(temp1.begin(),'0');
        }
    }
    string temp3;
    temp3.resize(maxLength);
    int next=0;
    for(int i=maxLength-1; i>=0 ; i--){

        int number=(temp1[i]-'0'+temp2[i]-'0'+next);
        if(number>=2){
            number-=2;
            next=1;
        }
        else{
            next=0;
        }
        temp3[i]=number+'0';
    }
    if(next==1){
        temp3.insert(temp3.begin(),'1');
    }

    

    while(1){
        if(temp3.size()==1 && temp3=="0"){
            break;
        }
        else if(temp3[0]=='0'){
            temp3.erase(temp3.begin());
        }
        else{
            break;
        }
    }
    cout<<temp3<<endl;

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}