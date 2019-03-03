#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i=1; i<=9; i++)
        scanf("%d",&arr[i]);

    int max=arr[1];
    int a=1;
    for(int i=2;i<=9; i++ ){
        if(max<arr[i]){
            max=arr[i];
            a=i;
        }
    }
    printf("%d\n%d\n",max,a);
    return 0;
}