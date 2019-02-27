#include <iostream>
using namespace std;

int main(){
    int n;
    int tea[5];
    int ans=0;
    scanf("%d", &n);

    for(int i=0; i<5; i++)
        scanf("%d",&tea[i]);

    for(int i=0; i<5;i ++)
        if(tea[i]==n) ans++;


    printf("%d\n",ans);

    return 0;
    
}