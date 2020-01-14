#include <bits/stdc++.h>
using namespace std;
long long a,b,c;

long long Mul(long long A,long long B, long long C){
    if(B==0)return 1;
    long long val=Mul(A,B/2,C);
    if(B%2==0)return val*val%C;
    return val*val%C *A%C;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>a>>b>>c;
    cout<<Mul(a,b,c)<<"\n";
    return 0;
}