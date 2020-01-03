#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void init (){
    for(int i=0; i<20; i++){
        v[i]=i+1;
    }
    return ;
}

void output(){
    for(int i=0; i<20 ; i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    v.resize(20);
    init();

    for(int i=0; i<10; i++){
        int a,b;
        cin>>a>>b;
        a=a-1;
        b=b-1;
        reverse(v.begin()+a,v.begin()+b+1);
    }

    output();
    return 0;
}