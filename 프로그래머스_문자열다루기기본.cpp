#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    int length=s.size();
    bool answer = true;
    if(!(length==4 || length==6)){
        return !answer;
    }
    for(int i=0; i<length; i++){
        int check=s[i]-'0';
        if(!(0<=check && check<=9)){
            return !answer;
        }
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges