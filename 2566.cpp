#include <iostream>
using namespace std;

int main(){
    int arr[10][10];

    int i,j;
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max=arr[1][1];
    int a=1,b=1;
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            if(max<arr[i][j]){
                max=arr[i][j];
                a=i,b=j;
            }
        }
    }
    printf("%d\n",max);
    printf("%d %d\n",a,b);
    return 0;
}