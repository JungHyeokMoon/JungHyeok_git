#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int Fibo[100001]={-1};
int Solve(int n){
    int &ret=Fibo[n];
    if(ret!=-1){
        return ret;
    }//이미계산됐다는소리니깐
    return ret=Solve(n-1)%1234567+Solve(n-2)%1234567;
}
int solution(int n) {
    fill(Fibo,Fibo+100001,-1);
    Fibo[0]=0;
    Fibo[1]=1;
    return Solve(n)%1234567;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges