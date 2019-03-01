#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,e;
    int ans=0;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    ans=a*a+b*b+c*c+d*d+e*e;
    ans=ans%10;

    printf("%d\n",ans);
}