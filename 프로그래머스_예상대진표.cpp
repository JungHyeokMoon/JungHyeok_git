#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MakeNumber(int num){
    if(num==2){
        return 1;
    }else{
        if(num%2==0){
            return num/2;
        }else{
            return num/2+1;
        }
    }
}
int solution(int n, int a, int b)
{   
    int answer=1;
    int MAX=max(a,b);
    int MIN=min(a,b);
    while(1){
        if((MIN/2)+1==(MAX/2) && MIN+1==MAX){//붙어있는것 판단
            return answer;
        }
        else{
            answer++;
            MAX=MakeNumber(MAX);
            MIN=MakeNumber(MIN);
            // cout<<"MAX : "<<MAX<<" , MIN : "<<MIN<<endl;
        }
    }

}
//4 1 4 
//1 2 => 2


//4 1 2 =>1

//8 1 8 
//1 4
//1 2 =>3

//8 1 4
//1 2 =>2

//16 3 11
//2 5
//1 3
//1 2 =>4

//16 3 7
//2 4
//1 2 =>3

//16 1 2=>1

//16 1 7
//1 4
//1 2 =>3 
