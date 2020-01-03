#include <bits/stdc++.h>
using namespace std;


int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    long long Youngsik=0;
    long long Minsik=0;
    for(int i=0; i<n; i++){
        long long score;
        cin>>score;
        Youngsik+=((score/30)+1)*10;
        Minsik+=((score/60)+1)*15;
    }

    if(Youngsik==Minsik){
        cout<<"Y"<<" "<<"M"<<" "<<Youngsik<<"\n";
    }
    else if(Youngsik>Minsik){
        cout<<"M"<<" "<<Minsik<<"\n";
    }
    else{
        cout<<"Y"<<" "<<Youngsik<<"\n";
    }

    return 0;
}