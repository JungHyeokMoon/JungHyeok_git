#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int a1,a2,a3;

    int ans=0;
    if(n<=99)
        printf("%d\n",n);
    else{
        for(int i=100; i<=n; i++){
            a1=i/100;
            a2=(i%100)/10;
            a3=(i%100)%10;
            if((a1-a2)==(a2-a3)) ans++;
        }
        printf("%d\n",ans+99);
    }

    return 0;
}