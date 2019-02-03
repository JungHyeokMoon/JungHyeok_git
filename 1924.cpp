#include <iostream>
using namespace std;

int main(){
    int twelve[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int x, y;
    int day=0;
    scanf("%d %d",&x ,&y);
    for(int i=0; i<x-1; i++)
        day+=twelve[i];

    day=day+y;

    if(day%7==0){
        printf("SUN\n");
    }
    else if(day%7==1){
        printf("MON\n");
    }
    else if(day%7==2){
        printf("TUE\n");
    }
    else if(day%7==3){
        printf("WED\n");
    }
    else if(day%7==4){
        printf("THU\n");
    }
    else if(day%7==5){
        printf("FRI\n");
    }
    else if(day%7==6){
        printf("SAT\n");
    }
    
    return 0;

}
