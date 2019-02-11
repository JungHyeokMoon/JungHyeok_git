#include <iostream>
using namespace std;

int fibo(int n){
    if(n<=1)
        return n;
    else 
        return fibo(n-2)+fibo(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    cout<<fibo(n)<<endl;
    
    return 0;
}