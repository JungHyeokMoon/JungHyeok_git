#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt=0;
    int found=n+1;
    while(n!=0){
        if(n%2==1){
            cnt++;
        }
        n=n>>1;
    }
    for(int i=found; i<=1000000; i++){
        int temp=i;
        int tempCount=0;
        while(temp!=0){
            if(temp%2==1){
                tempCount++;
            }
            temp=temp>>1;
        }
        if(tempCount==cnt){
            answer=i;
            break;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges