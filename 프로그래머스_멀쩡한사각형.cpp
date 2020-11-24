#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b){
    if(a<b) swap(a,b);
    while(b!=0){
        int n=a%b;
        a=b;
        b=n;
    }
    return a;
}
long long solution(int w,int h) {
    long long g=gcd(w,h);
    long long answer = (long long)w*h-(w+h-g);
    return answer;
}

int main(){
    cout<<solution(8,12)<<endl;

    return 0;
}
