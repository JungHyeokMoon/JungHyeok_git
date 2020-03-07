#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int getlcd(int a, int b){
    while(b>0){
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int getlcm(int a, int b){
    return (a*b)/getlcd(a,b);
}
int solution(vector<int> arr) {
    int answer = 1;
    int length=arr.size();
    
    for(int i=0; i<length ; i++){
        answer=getlcm(answer,arr[i]);
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges