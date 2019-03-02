#include <iostream>
using namespace std;

int main(){
    long long n;
    scanf("%lld",&n);

    long long second=0;
    long long i=1;
    while(n>0){
        if(i>n)
            i=1;
        
        n=n-i;
        i++;
        second++;
    }
    printf("%lld\n",second);

    return 0;
}