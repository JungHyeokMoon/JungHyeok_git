#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    long long *arr=new long long[n];
    long long ans=0;
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
        
    int check;//�������� ������� Ȯ�ο�
    int d,r;
    if(arr[2]-arr[1]==arr[1]-arr[0]){
        check=1; //����
        d=arr[1]-arr[0];
    }
    else if(arr[2]/arr[1]==arr[1]/arr[0]){
        check=2;
        r=arr[1]/arr[0];//����
    }

    if(check==1)
        printf("%lld",arr[n-1]+d);
    else if(check==2)
        printf("%lld",arr[n-1]*r);
    
    return 0;
}