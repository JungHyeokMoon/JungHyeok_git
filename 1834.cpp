#include <iostream>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    
    long long sum=0;

     
    for(long long i=1; i<n; i++){
        sum=sum+(n*i+i);
    }
    printf("%lld\n",sum);

    return 0;
}