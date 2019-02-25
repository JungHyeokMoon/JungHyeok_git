#include <iostream>
using namespace std;

int main(){
    int a,b;
    char c;

    

    while(cin>>a>>c>>b){
    if(c=='W'){
        if(a==0&&b==0)
            break;
        else if(a-b<-200)
            printf("Not allowed\n");
        else
            printf("%d\n",a-b);
        
    }
    else if(c=='D')
        printf("%d\n",a+b);
    }

    return 0;
}