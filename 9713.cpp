#include <iostream>
using namespace std;

int sumofoddsequence(int n){
    if(n==1)
        return 1;
    else
        return 2*n-1+sumofoddsequence(n-1);
    
    
}
int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        printf("%d\n",sumofoddsequence(i));

    return 0;
}