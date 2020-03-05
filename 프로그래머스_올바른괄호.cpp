#include<string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    int length=s.size();
    for(int i=0; i<length; i++){
        if(s[i]=='('){
            stk.push(s[i]);
        }else{
            if(stk.empty()){
                answer=false;
                break;
            }else{
                stk.pop();
            }
        }
    }
    if(!stk.empty()){
        answer=false;
    }
    return answer;
}
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges