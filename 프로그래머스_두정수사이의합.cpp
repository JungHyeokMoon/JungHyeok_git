#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int a, int b) {
    
    long long answer = 0;
    
    if(a==b){
        answer=a;
    }
    else{
        int Max=max(a,b);
        int Min=min(a,b);
        int number=(Max-Min)+1;
        double multi=(double(Max+Min)/2);
        // cout<<"큰 수 : "<<Max<<", 작은 수 :"<<Min<<" 몇 개 :"<<number<<", 중간값 : "<<multi<<endl;
        answer=number*multi;
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges