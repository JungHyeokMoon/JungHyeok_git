#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(int n) {
    string answer = "";
    string watermelon="수박";
    string water="수";
    int number=n/2;
    for(int i=0; i<number; i++){
        answer+=watermelon;
    }
    if(n%2==1){
        answer+=water;
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges