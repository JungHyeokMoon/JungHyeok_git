#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int ret=0;
    while(scanf("%d",&n)!=EOF){
        if(n>0)ret++;
    }
    cout<<ret<<"\n";

    return 0;
}